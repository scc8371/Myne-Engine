#pragma once
#include <opengl/opengl.h>
#include "Vector2.h"

class Circle{
public:
    Circle(float x, float y, float radius);
    bool isColliding(Circle other);
    Vector2 getPosition();
    float getRadius();
private:
    float x, y, radius;
};
