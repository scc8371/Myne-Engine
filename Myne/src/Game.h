#pragma once
#include "../library/opengl.h"
#include "ResourceManager.h"
#include "gl/SpriteBatch.h"

class Game{
public:
    Game();
    virtual void initialize();
    virtual void update(float dt);
    virtual void draw(SpriteBatch* _spriteBatch);
};