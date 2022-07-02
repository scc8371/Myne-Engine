#include "UIElement.h"

UIElement::UIElement(UIRectangle bounds){
    isActive = false;
    focused = false;

    this->bounds = bounds;
}

void UIElement::checkHover(Rectangle parentRect, Vector2 mousePos){
    if(!isActive) return;
}

void UIElement::update(Rectangle parentRect, Vector2 mousePos, float dt){
    focused = false;
}

void UIElement::draw(Rectangle parentRect){
    if(!isActive) return;
}
