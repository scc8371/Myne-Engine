#pragma once
#include <AL/al.h>
#include <iostream>
#include "WavReader.h"

class Song{
public:
    Song(const char* path, float loopPoint = 0);
    Song(){}
    ALuint get_introBuffer(){ return introBuffer; }
    ALuint get_loopBuffer(){ return loopBuffer; }
    bool get_hasIntro(){ return hasIntro; }

    float volume = 1.0f;
private:
    ALuint introBuffer, loopBuffer;
    bool hasIntro; 
};  

