#include "Circle.h"

Circle::Circle(float x, float y, float radius){
    this->x = x;
    this->y = y;
    this->radius = radius;
}

bool Circle::isColliding(Circle other){
    return Vector2(x - other.x, y - other.y).magnitude() < radius + other.radius;
}

Vector2 Circle::getPosition(){
    return Vector2(x, y);
}

float Circle::getRadius(){
    return radius;
}