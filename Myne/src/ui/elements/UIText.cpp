#include "UIText.h"

//TODO -- LOOK FOR MEMORY LEAKS, COMMENT
UIText::UIText(Font* font, UIRectangle bounds,
        uiUpdate update, TextAlign align,
        Color color) : UIElement(bounds){

    this->isActive = true;
    this->font = font;
    this->updateFunct = update;
    this->align = align;
    this->color = color;
}

void UIText::update(Rectangle parentRect, Vector2 mousePos, float dt){
    if(!isActive) return;

    if(updateFunct){
        this->text = updateFunct();
    }
}

void UIText::draw(Rectangle parentRect){
    if(!isActive) return;
    if(text == "") return;

    Rectangle bounds = this->bounds.toRectangle(parentRect);

    float h = 0;

    float posY = bounds.y + (bounds.height - h) / 2;

}