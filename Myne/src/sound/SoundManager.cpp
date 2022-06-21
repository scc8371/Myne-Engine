#include "SoundManager.h"


SoundManager* SoundManager::getInstance(){
    if(!instance) instance = new SoundManager();
    return instance;
}

SoundManager::SoundManager(){

    //audio system init
    device = alcOpenDevice(NULL);
    if(device == NULL){
        std::cout << "OpenAL refused to get default device" << std::endl;
        return;
    }

    audioContext = alcCreateContext(device, NULL);

    if(audioContext == NULL){
        std::cout << "OpenAL refused to make current context" << std::endl;
    }

    //generates source for song
    alGenSources(1, &musicSource);

    //generates source for sounds
    alGenSources(SOURCES, &soundSources[0]);
}

void SoundManager::updateAudio(){
    //used in game to update audio. Supposed to be called every frame

    ALint state;

    //checks if the music is currently playing
    alGetSourcei(musicSource, AL_SOURCE_STATE, &state);
    
    //checks if the audio stopped
    //and if a loop has been queued
    if(state != AL_PLAYING && loopBuffer != 0){
        //changes current state to play the loop
        alSourcei(musicSource, AL_BUFFER, loopBuffer);
        alSourcei(musicSource, AL_LOOPING, 1);

        //plays the music
        alSourcePlay(musicSource);
    }
    
    auto error = alGetError();

    if(error != AL_NO_ERROR){
        printf("OpenAL error: %s", std::to_string(error));
    }
}

void SoundManager::play(Song song){
    //prevents the song from infinitely repeating.
    if(song.get_loopBuffer() == loopBuffer) return;

    //sets the pitch of the song
    alSourcef(musicSource, AL_PITCH, 1.0f);

    //checks if the song has an intro segment
    if(song.get_hasIntro()){
        //stops current track and plays the intro
        alSourceStop(musicSource);
        alSourcei(musicSource, AL_BUFFER, song.get_introBuffer());
        alSourcei(musicSource, AL_LOOPING, 0);
        alSourcePlay(musicSource);
    }
    else{
        //does not play intro and immediately starts the loop
        alSourceStop(musicSource);
    }

    loopBuffer = song.get_loopBuffer();
}

void SoundManager::play(Sound sound){
    ALint state;
    //checks if the source is already playing
    alGetSourcei(soundSources[nextSoundSource], AL_SOURCE_STATE, &state);
    alSourcei(soundSources[nextSoundSource], AL_BUFFER, sound.get_buffer());
}