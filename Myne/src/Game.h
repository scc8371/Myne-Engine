#pragma once
#include <opengl/opengl.h>
#include "ResourceManager.h"
#include "gl/SpriteBatch.h"
#include "events/InputManager.h"
#include "events/EventManager.h"

class Game{
public:
    Game();
    virtual void initialize();
    virtual void update(float dt);
    virtual void draw(SpriteBatch* _spriteBatch);

    //input handling
    virtual void kbPress(int* key);
    virtual void kbRelease(int* key);
    virtual void mousePress(int* button);
    virtual void mouseRelease(int* button);
    Vector2 getMousePos();
};
