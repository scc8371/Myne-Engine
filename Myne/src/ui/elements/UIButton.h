#pragma once
#include "../../utils/Vector2.h"
#include "../../utils/Rectangle.h"
#include "UIElement.h"
#include "../../utils/Color.h"
#include "../../utils/Font.h"
#include "../tools/UISprite.h"

class UIButton : public UIElement{
public:
    UIButton(
        UISprite* buttonMain,
        UISprite* buttonToggle,
        UISprite* buttonDisabled,
        Font font,
        UIRectangle bounds, 
        uiAction action = NULL, 
        const char* text = "",
        isDisabled checkDisabled = NULL, 
        Sprite* sprite = NULL,
        Sprite* toggleSprite = NULL,
        bool toggle = false
        );

    ~UIButton();

private:
    UISprite* buttonActive;
    UISprite* buttonToggle;
    UISprite* buttonDisable;

    Font* font;
    uiAction action;
    const char* text;
    uiUpdate textUpdate;
    Sprite sprite;
    Sprite toggleSprite;
    bool hasSprite;
    bool hasToggleSprite;
    UISprite normalUI, clickedUI, disabledUI, focusedUI;
    bool toggle;
    bool pressed;
    Color color;

    void checkHover(Rectangle parentRect, Vector2 mousePos) override;
    void update(Rectangle parentRect, Vector2 mousePos, float dt) override;
    void click(int button) override;
    void drag(int button) override;
    void draw(Rectangle parentRect) override;
    void setTextures();

};
