#include "UIButton.h"

UIButton::UIButton(
        UISprite* buttonActive,
        UISprite* buttonToggle,
        UISprite* buttonHover,
        UISprite* buttonDisable,
        Font font,
        UIRectangle bounds,
        Color fontColor,
        Color disabledColor,
        uiAction action = NULL, 
        const char* text = "",
        isDisabled checkDisabled, 
        Sprite* sprite,
        Sprite* toggleSprite,
        bool toggle) : UIElement(bounds){

            //init bounds and rendering params
            this->isActive = true;
            this->bounds = bounds;
            this->checkDisabled = checkDisabled;

            this->font = &font;
            this->buttonActive = buttonActive;
            this->buttonToggle = buttonToggle;
            this->buttonHover = buttonHover;   
            this->buttonDisable = buttonDisable;

            this->sprite = sprite;
            this->toggleSprite = toggleSprite;
            this->action = action;

            this->text = text;
            this->toggle = toggle;

            this->color = fontColor;
            this->disabledColor = disabledColor;
        }

UIButton::UIButton(
        UISprite* buttonMain,
        Font font,
        UIRectangle bounds) 
        : UIButton(buttonMain, buttonMain, buttonMain, buttonMain,
            font, bounds, Color(255, 255, 255), Color(255, 0, 0),
            NULL, "", NULL, NULL, NULL, false){}

UIButton::~UIButton(){
    delete text;
}

//checks if the mouse is inside the bounds of the uiButton
void UIButton::checkHover(Rectangle parentRect, Vector2 mousePos){
    focused = false;

    if(!isActive) return;

    if(checkDisabled && checkDisabled()) return;

    Rectangle temp = bounds.toRectangle(parentRect);

    if(temp.contains(mousePos)){
        focused = true;
    }
}

void UIButton::click(int button){
    if(toggle){
        pressed = !pressed;
        
        if(action){
            action((int)pressed);
        }
    }
    else{
        if(action){
            action(button);
        }     
    }
}

void UIButton::draw(Rectangle parentRect){
    if(!isActive) return;

    Rectangle temp = bounds.toRectangle(parentRect);
    UISprite* sprite = buttonActive;

    Color tempColor = color;
    
    //button is disabled (cannot be clicked)
    if(checkDisabled){
        if(checkDisabled()){
            tempColor = disabledColor;

            //changes sprite to disabled
            if(buttonDisable){
                sprite = buttonDisable;
            }
        }

        else if(focused){
            sprite = buttonHover;
        }
    }

    //button is focused (mouse is hovering over it)
    else if(focused){
        sprite = buttonHover;
    }

    if(sprite){
        sprite->draw(temp);
    }

    //centers the text, positions the icon to the left of the text.
    float posX = temp.x + ((temp.width - temp.height) -
        font->size(text).x) / 2;

    float posY = temp.y + ((temp.height) - font->size(text).y) / 2;

    if(this->sprite){
        //height is put in twice to ensure the icon is drawn as a square
        sprite->
            draw(Rectangle(posX, temp.y, temp.height, temp.height), tempColor);
    }

    //draw focused icon
    if(toggleSprite){
        if(pressed){
            //height is put in twice to ensure the icon is drawn as a square
            toggleSprite->
                draw(Rectangle(posX, temp.y, temp.height, temp.height), tempColor);
        }

        if(focused){
            toggleSprite->
                draw(Rectangle(posX, temp.y, temp.height, temp.height),
                    Color(tempColor.r, tempColor.g, tempColor.b, tempColor.a/2));
        }
    }

    if(text != ""){
        if(sprite){
            //recenters the text if there is a sprite
            posX = (temp.x + temp.height + BUTTON_BORDER) +
                ((temp.width - temp.height) - font->size(text).x) / 2;           
        }

        font->draw(text, Vector2(posX, posY), tempColor);
    }
}

void UIButton::update(Rectangle parentRect, Vector2 mousePos, float dt){
    if(!isActive) return;

    if(textUpdate){
        text = textUpdate();
    }
}