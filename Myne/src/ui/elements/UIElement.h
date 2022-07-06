#pragma once
#include "../../utils/Rectangle.h"
#include "../../utils/Vector2.h"
#include "../../texture/Texture.h"
#include "../tools/UIRectangle.h"

typedef void (*uiAction)(int i);
typedef const char* (*uiUpdate)();
typedef bool (*isDisabled)();

class UIElement{
public:
    UIElement(UIRectangle bounds);
    virtual void checkHover(Rectangle parentRect, Vector2 mousePos);
    virtual void update(Rectangle parentRect, Vector2 mousePos, float dt);
    virtual void click(int button){}
    virtual void drag(int button){}
    virtual void draw(Rectangle parentRect);

    bool isActive;
    bool focused;

protected:
    UIRectangle bounds; 
    isDisabled checkDisabled = NULL;
};
