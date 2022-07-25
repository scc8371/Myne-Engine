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

    Rectangle offset(Vector2 offset);

    float getWidth() {return width;}
    float getHeight() {return height;}
    bool intersects(Rectangle other);
    Rectangle getIntersection(Rectangle other);
    float x, y, width, height;
};
