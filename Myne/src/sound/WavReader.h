#include <AL/al.h>
#include <iostream>
#include <fstream>
#include <string>

class WavReader{
public:
    WavReader(const char* path);
    ~WavReader();
    void* data;
    int size, freq, channels;
};