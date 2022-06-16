#pragma once
#include <opengl/opengl.h>

class Color{
public:
    Color(char r, char g, char b, char a = 255);
    char r, g, b, a;

    GLfloat* toFloats();
    Color mix(Color other, float ratio);

};