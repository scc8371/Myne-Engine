#include "Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

GLfloat* Color::toFloats(){
    GLfloat* temp = new GLfloat[4]{(GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255, (GLfloat)a/255};  
    return temp;
}

//lerp function to mix two colors together
//other is the color to mix with, ratio is how much the second color is mixed in
Color Color::mix(Color other, float ratio){
    float aFactor = ratio;
    float bFactor = 1 - ratio;
    Color color(
        r * aFactor + other.r * bFactor,
        g * aFactor + other.g * bFactor,
        b * aFactor + other.b * bFactor,
        a * aFactor + other.a * bFactor
    );

    return color;
}