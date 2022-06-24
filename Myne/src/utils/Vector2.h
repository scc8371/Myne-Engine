#pragma once
#include <opengl/opengl.h>
#include <math.h>
#include <iostream>

struct Vector2{
    public:
    Vector2(GLfloat x, GLfloat y);
    Vector2(int x, int y);
    Vector2(double x, double y);
    Vector2(){}
    GLfloat x;
    GLfloat y;

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
    Vector2* normalize();
    GLfloat magnitude();
};
