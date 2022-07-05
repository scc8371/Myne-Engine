#pragma once
#include <opengl/opengl.h>
#include "Vector2.h"

class Rectangle{

public:
    Rectangle(float x, float y, float width, float height);
    Rectangle(const Rectangle &other);
    Rectangle(){}
    bool isColliding(Rectangle other);
    bool contains(Vector2 pos);

    Vector2 getSize();
    void setSize(Vector2 size);
    
    Vector2 getLocation() {return Vector2(x, y); }
    void setLocation(Vector2 location);

    float getX() {return x;}
    float getY() {return y;}

    float getWidth() {return width;}
    float getHeight() {return height;}

    float x, y, width, height;
};
