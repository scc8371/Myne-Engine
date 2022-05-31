#include "Vector2.h"

Vector2::Vector2(GLfloat x, GLfloat y){
    this->xVal = x;
    this->yVal = y;
}

GLfloat Vector2::x(){
        return this->xVal;
}

GLfloat Vector2::y(){
    return this->yVal;
}

Vector2* Vector2::normalize(){
    GLfloat mag = magnitude();

    if(mag <= 0){
        return new Vector2(0, 0);
        std::cout << "Invalid magnitude detected! Check Vector2 inputs." << std::endl;
    }
    else{
        return new Vector2(xVal / mag, yVal / mag);
    }
}

GLfloat Vector2::magnitude(){
    return sqrtf(powf(xVal, 2) + powf(yVal, 2));
}

Vector2 Vector2::operator+(const Vector2& vector){
    GLfloat x = xVal + vector.xVal;
    GLfloat y = yVal + vector.yVal;

    return Vector2(x, y);
}

Vector2 Vector2::operator+=(const Vector2& vector){
    GLfloat x = xVal + vector.xVal;
    GLfloat y = yVal + vector.yVal;

    return Vector2(x, y);
}

Vector2 Vector2::operator-(const Vector2& vector){
    GLfloat x = xVal - vector.xVal;
    GLfloat y = yVal - vector.yVal;

    return Vector2(x, y);
}

Vector2 Vector2::operator-=(const Vector2& vector){
    GLfloat x = xVal - vector.xVal;
    GLfloat y = yVal - vector.yVal;

    return Vector2(x, y);
}

Vector2 Vector2::operator*(const GLfloat& scalar){
    GLfloat x = xVal * scalar;
    GLfloat y = yVal * scalar;

    return Vector2(x, y);
}

Vector2 Vector2::operator*=(const GLfloat& scalar){
    GLfloat x = xVal * scalar;
    GLfloat y = yVal * scalar;

    return Vector2(x, y);
}

Vector2 Vector2::operator/(const GLfloat& scalar){
    GLfloat x = xVal / scalar;
    GLfloat y = yVal / scalar;

    return Vector2(x, y);
}

Vector2 Vector2::operator/=(const GLfloat& scalar){
    GLfloat x = xVal / scalar;
    GLfloat y = yVal / scalar;

    return Vector2(x, y);
}

Vector2& Vector2::operator=(const Vector2& vector){
    if(this == &vector){
        return *this;
    }
    else{
        xVal = vector.xVal;
        yVal = vector.yVal;

        return *this;
    }
}

void Vector2::setAngle(GLfloat radians){
    xVal = cos(radians) * xVal - sin(radians) * yVal;
    yVal = sin(radians) * xVal + cos(radians) * yVal;
}
