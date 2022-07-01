#pragma once 
#include <AL/al.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>

class WavReader{
public:
    WavReader(const char* path);
    ~WavReader();
    void* data;
    uint32_t size, freq, channels;
};