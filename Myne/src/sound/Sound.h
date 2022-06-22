#pragma once
#include <AL/al.h>
#include <iostream>
#include "WavReader.h"

class Sound{
public:
    Sound(const char* path);
    Sound(){}

    ALint get_buffer(){ return buffer; }
    float volume = 1.0f;

private:
    ALint buffer = 0;
};
