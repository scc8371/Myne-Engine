#include "Sound.h"

//constructs a new sound object
//inputs: string path: the path to the sound file
//outputs: none
Sound::Sound(const char* path){
    auto sound = WavReader(path);  
    
    alGenBuffers(1, (ALuint*)(&buffer));
    
    alBufferData(buffer, AL_FORMAT_STEREO16, sound.data, sound.size, sound.freq);    
}

