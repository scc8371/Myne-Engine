#pragma once
#include <AL/al.h>
#include <iostream>
#include "WavReader.h"

class Sound{
public:
    Sound(const char* path);
    Sound(){}

    ALuint get_buffer(){ return (ALuint)buffer; }
    float volume = 1.0f;

private:
    ALint buffer = 0;
};
