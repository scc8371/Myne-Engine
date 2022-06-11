#pragma once
#include "../library/opengl.h"
#include "ResourceManager.h"
class Game{
public:
    Game();
    virtual void update(float dt);
    virutal void initialize();
    virtual void draw();
    virtual void drawLoading(GLwindow window);
private:
    float calcDt();
    float dt;
}