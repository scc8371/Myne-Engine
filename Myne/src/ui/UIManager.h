#pragma once

#include "elements/UIElement.h"
#include "../utils/Vector2.h"
#include "../utils/Rectangle.h"
#include <vector>
#include "../events/EventManager.h"

class UIManager{
public: 
    static UIManager* getInstance();

    void setMousePos(Vector2 pos);
    Vector2 getMousePos() { return mousePos; }

    void setSize(Vector2 size){ this->size = size; }
    Vector2 getSize() { return size; }

    UIElement* getDrag() { return drag; }
    void setDrag(UIElement* drag) { this->drag = drag; }

    void setLastButton(int button){ last = button; }
    int getLastButton() { return last; }

    std::vector<UIElement*> getElements();

    void addUIElement(UIElement* element);
    void addUIElements(std::vector<UIElement*> elements);
    void drawUI();
    void updateUI(float dt);
    
    void setUIActive(int index, bool active);
    
private:
    static UIManager* instance;
    UIManager();

    std::vector<UIElement*> elements;
    Vector2 size;
    Vector2 mousePos;  

    UIElement* drag;
    int last;
};
void uiMouseMove(void* data);
void uiMousePress(void* data);
void uiMouseRelease(void* data);
void uiWindowResize(void* data);


