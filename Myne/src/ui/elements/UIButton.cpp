#include "UIButton.h"

UIButton::UIButton(
        UISprite* buttonMain,
        UISprite* buttonToggle,
        UISprite* buttonDisabled,
        Font font,
        UIRectangle bounds, 
        uiAction action, 
        const char* text,
        isDisabled checkDisabled, 
        Sprite* sprite,
        Sprite* toggleSprite,
        bool toggle = false) : UIElement(bounds){

            //init bounds and rendering params
            this->isActive = true;
            this->bounds = bounds;
            this->checkDisabled = checkDisabled;

            this->font = &font;
        }

UIButton::~UIButton(){
    delete font;
    delete buttonActive;
    delete buttonToggle;
    delete buttonDisable;
}

void UIButton::setTextures(){

}