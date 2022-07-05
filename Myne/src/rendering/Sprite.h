#pragma once
#include "../utils/Vector2.h"
#include "../utils/Rectangle.h"
#include "../texture/Texture.h"
#include "../gl/SpriteBatch.h"

class Sprite{
public:
    Sprite(Texture texture, Rectangle source);
    Sprite(Texture texture, float x, float y, float width, float height);

    void draw(Rectangle destination, Color color);
protected:
    Texture texture;
    Rectangle source;
};