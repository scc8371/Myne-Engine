#pragma once
#include <AL/al.h>
#include <AL/alext.h>
#include <opengl/opengl.h>
#include <iostream>
#include "Song.h"
#include "Sound.h"

//pre-allocated.. higher numbers = more RAM usage.
const int SOURCES = 60;

class SoundManager{
public:
    static SoundManager* getInstance();   
    ~SoundManager();
    void updateAudio();
    void initialize();
    void play(Song song);
    void play(Sound sound);


private:
    static SoundManager* instance;
    SoundManager();

    ALCdevice* device;
    ALCcontext* audioContext;

    //sources
    ALuint musicSource = 0;
    ALuint soundSources[SOURCES];

    int nextSoundSource = 0;
    ALuint loopBuffer = 0;
};


