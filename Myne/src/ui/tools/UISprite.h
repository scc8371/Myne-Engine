#pragma once
#include "../../utils/Vector2.h"
#include "../../utils/Rectangle.h"
#include "../../texture/Texture.h"
#include "../../rendering/Sprite.h"

class UISprite : public Sprite{
public:
    UISprite(Texture texture, Rectangle source, Rectangle center, Vector2 scale);
    UISprite(){}

    void setCenter();
    void draw(Rectangle destination, Color color = Color(255, 255, 255)) override;
private:
    void drawSection(Vector2 point, Rectangle destination, Color color);
    Rectangle renderSections[3][3];
    Rectangle center;
    Vector2 scale;
};
