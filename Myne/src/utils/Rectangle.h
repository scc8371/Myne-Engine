#pragma once
#include "../library/opengl.h"
#include "Vector2.h"

class Rectangle{

public:
    Rectangle(float x, float y, float width, float height);
    bool isColliding(Rectangle other);
    bool contains(Vector2 pos);
    Vector2 getSize();
    Vector2 getLocation();
private:
    int x, y, width, height;    
};