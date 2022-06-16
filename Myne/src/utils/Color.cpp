#include "Color.h"

Color::Color(char r, char g, char b, char a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

GLfloat* Color::toFloats(){
    GLfloat arr[4] = {r/255, g/255, b/255, a/255};
    return arr;
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