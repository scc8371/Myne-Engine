#pragma once
#include <opengl/opengl.h>
#include <iostream>

class Color{
public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    Color(){}
    uint8_t r, g, b, a;

    GLfloat* toFloats();
    Color mix(Color other, float ratio);

};