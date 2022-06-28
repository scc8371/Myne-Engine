#include "Sound.h"

Sound::Sound(const char* path){
    auto sound = WavReader(path);  
    
    alGenBuffers(1, (ALuint*)(&buffer));

    //size seems WAY too large.
    printf("%s, %i, %i", sound.data, sound.size, sound.freq);
    
    //this line ise erroring.. bad data??
    alBufferData(buffer, AL_FORMAT_STEREO16, sound.data, sound.size, sound.freq); 

    auto error = alGetError();

    if(error != AL_NO_ERROR){
        printf("OpenAL error: %i\n", error);
    }
}

