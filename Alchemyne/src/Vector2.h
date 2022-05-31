#pragma once
#include "../library/GLFW/include/GLFW/glfw3.h"
#include <math.h>
#include <iostream>

struct Vector2{
    public:
    Vector2(GLfloat x, GLfloat y);
    GLfloat x();
    GLfloat y();

    //operation overloads for vector math
    Vector2 operator+(const Vector2& vector);
    Vector2 operator+=(const Vector2& vector);
    Vector2 operator-(const Vector2& vector);
    Vector2 operator-=(const Vector2& vector);
    Vector2 operator*(const GLfloat& scalar);
    Vector2 operator*=(const GLfloat& scalar);
    Vector2 operator/(const GLfloat& scalar);
    Vector2 operator/=(const GLfloat& scalar);

    Vector2& operator=(const Vector2& other);

    //vector rotation
    void setAngle(GLfloat radians);
    private:
    GLfloat xVal;
    GLfloat yVal;

    Vector2* normalize();
    GLfloat magnitude();
};