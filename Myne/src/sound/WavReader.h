#include <AL/al.h>
#include <iostream>
#include <fstream>

class WavReader{
public:
    WavReader(const char* path);
    void* data;
    int size, freq, channel;
};