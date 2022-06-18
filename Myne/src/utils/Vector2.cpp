#include "Vector2.h"

Vector2::Vector2(GLfloat x, GLfloat y){
    this->x = x;
    this->y = y;
}
Vector2::Vector2(int x, int y){
    this->x = (GLfloat)x;
    this->y = (GLfloat)y;
}

Vector2::Vector2(double x, double y){
    this->x = (GLfloat)x;
    this->y = (GLfloat)y;
}

//normalizes a vector2.. returns a copy
Vector2* Vector2::normalize(){
    GLfloat mag = magnitude();

    if(mag <= 0){
        return new Vector2(0, 0);
        std::cout << "Invalid magnitude detected! Check Vector2 inputs." << std::endl;
    }
    else{
        return new Vector2(x / mag, y / mag);
    }
}

//returns the magnitude of a Vector2
GLfloat Vector2::magnitude(){
    return sqrtf(powf(x, 2) + powf(y, 2));
}

Vector2 Vector2::operator+(const Vector2& vector){
    GLfloat xTemp = x + vector.x;
    GLfloat yTemp = y + vector.y;

    return Vector2(xTemp, yTemp);
}

Vector2 Vector2::operator+=(const Vector2& vector){
    return *this = *this + vector;
}

Vector2 Vector2::operator-(const Vector2& vector){
    GLfloat xTemp = x - vector.x;
    GLfloat yTemp = y - vector.y;

    return Vector2(xTemp, yTemp);
}

Vector2 Vector2::operator-=(const Vector2& vector){
    return *this = *this - vector;
}

Vector2 Vector2::operator*(const GLfloat& scalar){
    GLfloat xTemp = x * scalar;
    GLfloat yTemp = y * scalar;

    return Vector2(xTemp, yTemp);
}

Vector2 Vector2::operator*=(const GLfloat& scalar){
    return *this = *this * scalar;
}

Vector2 Vector2::operator/(const GLfloat& scalar){
    GLfloat xTemp = x / scalar;
    GLfloat yTemp = y / scalar;

    return Vector2(xTemp, yTemp);
}

Vector2 Vector2::operator/=(const GLfloat& scalar){
    return *this = *this / scalar;
}

//sets one vector2 equal to another.
Vector2& Vector2::operator=(const Vector2& vector){
    if(this == &vector){
        return *this;
    }
    else{
        x = vector.x;
        y = vector.y;

        return *this;
    }
}

//sets the angle of a vector2
void Vector2::setAngle(GLfloat radians){
    x = cos(radians) * x - sin(radians) * y;
    y = sin(radians) * x + cos(radians) * y;
}
