#pragma once
#include <AL/al.h>
#include <iostream>
#include "WavReader.h"

class Song{
public:
    Song(const char* path, float loopPoint = 0);
    Song(){}
    ALint get_introBuffer(){ return introBuffer; }
    ALint get_loopBuffer(){ return loopBuffer; }
    bool get_hasIntro(){ return hasIntro; }

    float volume = 1.0f;
private:
    ALint introBuffer = 0, loopBuffer = 0;
    bool hasIntro = false; 
};  

