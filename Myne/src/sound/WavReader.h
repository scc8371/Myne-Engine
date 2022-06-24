#pragma once 
#include <AL/al.h>
#include "AudioFile.h"
#include <stdio.h>
#include <cstring>

class WavReader{
public:
    WavReader(const char* path);
    void* data;
    int size = 0, freq, channels;
};