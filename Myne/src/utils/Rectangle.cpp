#include "Rectangle.h"

//constructs a rectangle at (x, y) with a width and height of (width, height)
Rectangle::Rectangle(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Rectangle::Rectangle(const Rectangle &other){
    this->x = other.x;
    this->y = other.y;
    this->width = other.width;
    this->height = other.height;
}

//returns a vector2 of the rectangle's size
Vector2 Rectangle::getSize(){
    return Vector2(width, height);
}

void Rectangle::setLocation(Vector2 location){
    this->x = location.x;
    this->y = location.y;
}

void Rectangle::setSize(Vector2 size){
    this->width = size.x;
    this->height = size.y;
}

//offsets the rectangle by (x, y) 
//inputs: Vector2(x, y)
//output: Rectangle
Rectangle Rectangle::offset(Vector2 offset){
    Rectangle temp;
    
    temp.x = this->x + offset.x;
    temp.y = this->y + offset.y;
    temp.width = this->width;
    temp.height = this->height;
    return temp;
}

bool Rectangle::intersects(Rectangle other){
    return (this->x < other.x + other.width &&
            this->x + this->width > other.x &&
            this->y < other.y + other.height &&
            this->y + this->height > other.y);
}

Rectangle Rectangle::getIntersection(Rectangle other){
    Rectangle temp = Rectangle(0, 0, 0, 0);
    if(this->intersects(other)){
        temp.x = std::max(this->x, other.x);
        temp.y = std::max(this->y, other.y);
        temp.width = std::min(this->x + this->width, other.x + other.width) - temp.x;
        temp.height = std::min(this->y + this->height, other.y + other.height) - temp.y;
    }

    return temp;
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
