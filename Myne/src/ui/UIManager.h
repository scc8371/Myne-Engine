#pragma once

#include "elements/UIElement.h"
#include "../utils/Vector2.h"
#include "../utils/Rectangle.h"
#include <vector>
#include "../events/EventManager.h"

class UIManager{
public: 
    static UIManager* getInstance();

    std::vector<UIElement*> elements;
    Vector2 size;
    Vector2 mousePos;  

    UIElement* drag;
    int last;

    std::vector<UIElement*> getElements();

    void addUIElement(UIElement* element);
    void addUIElements(std::vector<UIElement*> elements);
    void drawUI();
    void updateUI(float dt);
    
    void setUIActive(int index, bool active);
    
private:
    static UIManager* instance;
    UIManager();   
};
void uiMouseMove(void* data);
void uiMousePress(void* data);
void uiMouseRelease(void* data);
void uiWindowResize(void* data);


