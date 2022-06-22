#include "Sound.h"

Sound::Sound(const char* path){
    auto sound = WavReader(path);
    alGenBuffers(1, (ALuint*)(&buffer));
    alBufferData(buffer, AL_FORMAT_STEREO16, sound.data, sound.size, sound.freq);
}
