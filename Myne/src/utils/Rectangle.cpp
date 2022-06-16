#include "Rectangle.h"

//constructs a rectangle at (x, y) with a width and height of (width, height)
Rectangle::Rectangle(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

//returns a vector2 of the rectangle's size
Vector2 Rectangle::getSize(){
    return Vector2(width, height);
}

//returns a vector2 of the rectangle's position 
Vector2 Rectangle::getLocation(){
    return Vector2(x, y);
}

//checks if a point lies within the rectangle
bool Rectangle::contains(Vector2 pos){
    return isColliding(Rectangle(pos.x, pos.y, 0, 0));
}

//AABB collision method 
bool Rectangle::isColliding(Rectangle other){
    return (x < other.x + other.width
    && x + width > other.x
    && y < other.y + other.height
    && y + height > other.y);
}