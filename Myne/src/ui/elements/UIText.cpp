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

    int size = strlen(text);
    char* tempStr = (char*)malloc(size);

    strcpy_s(tempStr, size, text);

    float height = 0;

    while(char* substring = strtok(text, "\n")){
        height += font->size(text).y;        
    }
    
    float posY = bounds.y + (bounds.height - height) / 2;
    posY = std::max(posY, bounds.y);

    //x positioning
    while(char* substring = strtok(text, "\n")){
        float posX = bounds.x;

        switch(align){
            case TextAlign::Center:
                posX = bounds.x + (bounds.width - font->size(text).x) / 2;
            break;
            case TextAlign::Right:
                posX = bounds.x + bounds.width - font->size(text).x;
            break;
        }

        posX = std::max(posX, bounds.x);
        font->draw(text, Vector2(posX, posY), color);
        posY += font->size(text).y;
    }
}