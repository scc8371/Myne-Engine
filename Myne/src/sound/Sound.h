#include <AL/al.h>
#include <opengl/opengl.h>
#include <iostream>

class Sound{
public:
    Sound(const char* path);
    ~Sound();

private:
    ALuint buffer;
};
