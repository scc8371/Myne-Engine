#include <AL/al.h>
#include <iostream>
#include "WavReader.h"

class Sound{
public:
    Sound(const char* path);
    ~Sound();

    ALuint get_buffer(){ return buffer; }

private:
    ALuint buffer;
};
