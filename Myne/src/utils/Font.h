#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H  
#include <iostream>
#include <math.h>

#include "../utils/Vector2.h"
#include "../ResourceManager.h"

struct CharacterInfo{
    float 
    ax,
    ay,
    bw, 
    bh,
    b1,
    bt, 
    tx;
};

struct Point{
    GLfloat
    x,
    y,
    s,
    t;
};

class Font{
public:

    Font(const char* fontPath, int fontSize);
    void draw(const char* text, Vector2 position);
    int size();

private:
    CharacterInfo info[128];
};