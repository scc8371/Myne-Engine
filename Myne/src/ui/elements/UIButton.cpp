#include "UIButton.h"
//TODO -- LOOK FOR MEMORY LEAKS, COMMENT, DEBUG
UIButton::UIButton(
        UISprite* buttonActive,
        UISprite* buttonToggle,
        UISprite* buttonHover,
        UISprite* buttonDisable,
        Font font,
        UIRectangle bounds,
        Color fontColor,
        Color disabledColor,
        uiAction action, 
        const char* text,
        isDisabled checkDisabled, 
        Sprite* sprite,
        Sprite* toggleSprite,
        bool toggle) : UIElement(bounds){

            //init bounds and rendering params
            this->isActive = true;
            this->bounds = bounds;
            this->checkDisabled = checkDisabled;

            this->font = font;
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

            this->focused = false;
        }

UIButton::UIButton(
        UISprite* buttonMain,
        Font font,
        UIRectangle bounds) 
        : UIButton(buttonMain, buttonMain, buttonMain, buttonMain,
            font, bounds, Color(255, 255, 255), Color(255, 0, 0),
            NULL, "", NULL, NULL, NULL, false){}


//checks if the mouse is inside the bounds of the uiButton
void UIButton::checkHover(Rectangle parentRect, Vector2 mousePos){
    this->focused = false;

    if(!isActive) return;

    if(checkDisabled && checkDisabled()) return;

    Rectangle temp = bounds.toRectangle(parentRect);

    if(temp.contains(mousePos)){
        this->focused = true;
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

    if(focused && buttonHover){
        buttonHover->draw(temp);
    }
    else if(buttonActive){
        buttonActive->draw(temp);
    }

    if(this->sprite){
        //centers the text, positions the icon to the left of the text.
        float posX = (temp.x) + ((temp.width - temp.height) - font.size(text).x) / 2;
        //height is put in twice to ensure the icon is drawn as a square
        this->sprite->
            draw(Rectangle(posX, temp.y, temp.height, temp.height), tempColor);
    }

    //draw focused icon
    if(toggleSprite){
        if(pressed){
            float posX = ((temp.x) + ((temp.width - temp.height) - font.size(text).x) / 2) - font.size(text).x;
            //height is put in twice to ensure the icon is drawn as a square
            toggleSprite->
                draw(Rectangle(posX, temp.y, temp.height, temp.height), tempColor);
        }

        //draws the focused icon if the button is not currently pressed
        if(focused){
            float posX = (temp.x) + ((temp.width - temp.height) - font.size(text).x) / 2;
            toggleSprite->
                draw(Rectangle(posX, temp.y, temp.height, temp.height),
                    Color(tempColor.r, tempColor.g, tempColor.b, tempColor.a/2));
        }
    }

    //draw text if there is any
    if(text != ""){
        float posX = ((temp.x + ((temp.width - font.size(text).x))/ 2));
        //printf float value
        float posY = (temp.y + ((temp.height - font.size(text).y) / 2)) + font.size(text).y;
        if(this->sprite){        
            //recenters the text if there is a sprite
            posX = (temp.x + temp.height + BUTTON_BORDER) +
                (((temp.width - temp.height) - font.size(text).x) / 2);           
        }

        font.draw(text, Vector2(posX, posY), tempColor);
    }
}

//updates the button's state
//parameters:
// parentRect: the rectangle of the parent element
// mousePos: the current mouse position
//dt: the time since the last update call
void UIButton::update(Rectangle parentRect, Vector2 mousePos, float dt){
    //returns if the button is not active
    if(!isActive) return;
    
    //updates the button's text if textUpdate is true
    if(textUpdate){
        text = textUpdate();
    }
}