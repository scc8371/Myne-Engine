#pragma once
#include <AL/al.h>
#include <opengl/opengl.h>
#include <iostream>

class SoundManager{
public:
    static SoundManager* getInstance();   
    ~SoundManager();
     void play();
};


