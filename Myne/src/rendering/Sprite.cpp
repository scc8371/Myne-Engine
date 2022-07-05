#include "Sprite.h"

Sprite::Sprite(Texture texture, Rectangle source){
    this->texture = texture;
    this->source = source;
}

Sprite::Sprite(Texture texture, float x, float y, float width, float height){
    this->texture = texture;
    this->source = Rectangle(x, y, width, height);
}

//Easier way to draw a texture, as you do not have to
//specify the location on the supplimented image.
void Sprite::draw(Rectangle destination, Color color){
    SpriteBatch::getInstance()->draw(texture, source, destination, color);
}