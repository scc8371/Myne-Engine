#pragma once
#include "../../utils/Vector2.h"
#include "../../utils/Rectangle.h"
#include "UIElement.h"
#include "../../utils/Color.h"
#include "../../utils/Font.h"
#include "../tools/UISprite.h"

//defines how thick button borders are (measured in pixels).
const int BUTTON_BORDER = 10;

class UIButton : public UIElement{
public:
    UIButton(
        UISprite* buttonActive,
        UISprite* buttonToggle,
        UISprite* buttonHover,
        UISprite* buttonDisable,
        Font font,
        UIRectangle bounds,
        Color fontColor = Color(255, 255, 255),
        Color disabledFontColor = Color(255, 0, 0),
        uiAction action = NULL, 
        const char* text = "",
        isDisabled checkDisabled = NULL, 
        Sprite* sprite = NULL,
        Sprite* toggleSprite = NULL,
        bool toggle = false
        );

    UIButton(
        UISprite* buttonMain,
        Font font,
        UIRectangle bounds
    );

    ~UIButton();

private:
    UISprite* buttonActive;
    UISprite* buttonToggle;
    UISprite* buttonHover;
    UISprite* buttonDisable;

    Font* font;
    uiAction action;
    const char* text;
    uiUpdate textUpdate;
    Sprite* sprite;
    Sprite* toggleSprite;
    bool toggle;
    bool pressed;

    Color color;
    Color disabledColor;

    void checkHover(Rectangle parentRect, Vector2 mousePos) override;
    void update(Rectangle parentRect, Vector2 mousePos, float dt) override;
    void click(int button) override;
    void draw(Rectangle parentRect) override;
};
