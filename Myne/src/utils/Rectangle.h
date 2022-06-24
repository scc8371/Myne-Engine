#pragma once
#include <opengl/opengl.h>
#include "Vector2.h"

class Rectangle{

public:
    Rectangle(float x, float y, float width, float height);
    Rectangle(){}
    bool isColliding(Rectangle other);
    bool contains(Vector2 pos);
    Vector2 getSize();
    Vector2 getLocation();

    float getX() {return x;}
    float getY() {return y;}

    float getWidth() {return width;}
    float getHeight() {return height;}

    float x, y, width, height;
};
