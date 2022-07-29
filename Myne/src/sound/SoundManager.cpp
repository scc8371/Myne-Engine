#include "SoundManager.h"
SoundManager* SoundManager::instance = NULL;

// https://www.openal.org/documentation/OpenAL_Programmers_Guide.pdf

//creates an instance of the sound manager singleton
SoundManager* SoundManager::getInstance(){
    if(!instance) instance = new SoundManager();
    return instance;
}

SoundManager::SoundManager(){}

//intializes the sound manager
void SoundManager::initialize(){
    //audio system init
    device = alcOpenDevice(NULL);

    if(device == NULL){
        std::cout << "OpenAL refused to get default device" << std::endl;
        return;
    }

    audioContext = alcCreateContext(device, NULL);
    alcMakeContextCurrent(audioContext);

    if(audioContext == NULL){
        std::cout << "OpenAL refused to make current context" << std::endl;
    }

    //generates source for song
    alGenSources(1, &musicSource);

    //generates source for sounds
    alGenSources(SOURCES, &soundSources[0]);   
}

//updates the audio in the sound manager, should be called in App()->update()
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
        printf("OpenAL error: %i\n", error);
    }
}

//plays a song
//inputs: Song song: the song to play  
//outputs: none
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
        alSourcef(musicSource, AL_GAIN, song.volume);
        alSourcePlay(musicSource);
    }
    else{
        //does not play intro and immediately starts the loop
        alSourceStop(musicSource);
    }

    

    loopBuffer = song.get_loopBuffer();
}

void SoundManager::play(Sound sound){
    //checks if the source is already playing
    alSourcef(soundSources[nextSoundSource], AL_PITCH, 1.0f);
     
    alSourcei(soundSources[nextSoundSource], AL_BUFFER, sound.get_buffer());   

     
    alSourcef(soundSources[nextSoundSource], AL_GAIN, sound.volume);

    alSourcePlay(soundSources[nextSoundSource]);
    nextSoundSource += 1;

    //loops to beginning if it gets to the end of the sources.
    if(nextSoundSource == SOURCES){
        nextSoundSource = 0;
    }   
}