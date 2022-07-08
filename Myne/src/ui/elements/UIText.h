#pragma once

#include "../../utils/Vector2.h"
#include "../../utils/Color.h"
#include "../../utils/Rectangle.h"
#include "../../utils/Font.h"
#include "UIElement.h"

enum TextAlign{
    Center,
    Left,
    Right
};

class UIText : public UIElement{

public:
    UIText(Font* font, UIRectangle bounds,
        uiUpdate update, TextAlign align = TextAlign::Center,
        Color color = Color(255, 255, 255));

private:
    Font* font;
    TextAlign align;
    Color color;
    uiUpdate updateFunct;
    char* text = "";

    void update(Rectangle parentRect, Vector2 mousePos, float dt) override;
    void draw(Rectangle parentRect) override;
};
