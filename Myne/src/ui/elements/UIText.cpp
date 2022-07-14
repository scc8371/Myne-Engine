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

    float height = 0;

    std::string temp = text;
    std::string temp2 = "";

    int index = 0;


    

    while(index != -1) {      
        index = temp.find_first_of("\n");

        temp2 = temp.substr(index + 1, temp.length());
        temp = temp.substr(0, index);
    
        height += font->size(temp).y;     

        if(index != -1){
            temp = temp2;
        }
    }

    float posY = bounds.y + (bounds.height - height) / 2;
    posY = std::max(posY, bounds.y);

    //x positioning
    temp = text;
    temp2 = "";

    index = 0;

    while(index != -1) {
        index = temp.find("\n");

        temp2 = temp.substr(index + 1, temp.length());
        temp = temp.substr(0, index);
        float posX = bounds.x;

        switch(align) {
            case TextAlign::Center:
                posX = bounds.x + (bounds.width - font->size(temp).x) / 2;
            break;
            case TextAlign::Right:
                posX = bounds.x + bounds.width - font->size(temp).x;
            break;            
        }
     
        const char* cstr = temp.c_str();

        posX = std::max(posX, bounds.x);
        font->draw(cstr, Vector2(posX, posY), color);
        posY += font->size(temp).y;

        if(index != -1){
            temp = temp2;
        }
    }
}
