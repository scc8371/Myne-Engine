#pragma once
#include "../library/opengl.h"
#include <vector>
#include "../texture/Texture.h"

class SpriteBatch{
    
    struct Vertex{
        GLfloat x, y, u, v;
    };

public:
    void draw(Texture texture);
private:
    std::vector<Vertex[6]> quads;

};