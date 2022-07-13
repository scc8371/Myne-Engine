#include "UIManager.h"

UIManager* UIManager::instance = NULL;

//UI Manager Constructor
UIManager::UIManager(){
    elements = std::vector<UIElement*>();
    size = Vector2(0, 0);
    mousePos = Vector2(0, 0);
    drag = NULL;
    last = 0;

    //attaches ui events to the event manager
    EventManager::getInstance()->attachEvent(MOUSE_MOVED, uiMouseMove);
    EventManager::getInstance()->attachEvent(MOUSE_PRESS, uiMousePress);
    EventManager::getInstance()->attachEvent(MOUSE_RELEASE, uiMouseRelease);
    EventManager::getInstance()->attachEvent(WINDOW_RESIZE, uiWindowResize);

}

//Set the mouse position
//Input: Vector2 pos - the new mouse position
//Output: void
void UIManager::setMousePos(Vector2 pos){
    mousePos = pos;
}

//RETURNS: std::vector<UIElement*> - the list of elements
//INPUTS: N/A
std::vector<UIElement*> UIManager::getElements(){
    return elements;
}

//Returns singleton instance of the UIManager
//Input: N/A
//Output: UIManager* - the singleton instance of the UIManager
UIManager* UIManager::getInstance(){
    if(!instance) instance = new UIManager();
    return instance;
}

//Adds a UIElement to the list of elements
//Input: UIElement* element - the element to add
//Output: void
void UIManager::addUIElement(UIElement* element){
    elements.push_back(element);
}

//Adds a list of elements to the UIManager
//Input: std::vector<UIElement*> elements - the list of elements to add
//Output: void
void UIManager::addUIElements(std::vector<UIElement*> elements){
    this->elements.insert(this->elements.end(), elements.begin(), elements.end());
}

void UIManager::drawUI(){
    //draws all ui elements
    for(int i = 0; i < elements.size(); i++){
        elements[i]->draw(Rectangle(0, 0, size.x, size.y));
    }
}

void UIManager::updateUI(float dt){
    //updates all ui elements
    for(int i = 0; i < elements.size(); i++){
        elements[i]->update(Rectangle(0, 0, size.x, size.y), mousePos, dt);
    }
}

void UIManager::setUIActive(int index, bool active){
    elements[index]->isActive = active;
}

//updates ui on mouse move
//Input: void* data - pointer to the new mouse position
//Output: void
void uiMouseMove(void* data){

    //get the new mouse position (event data)
    Vector2 pos = *(Vector2*)data;

    Vector2 sizeTemp = UIManager::getInstance()->getSize();

    //update the mouse position
    UIManager::getInstance()->setMousePos(pos);

    //checks if the mouse is over an element
    for(int i = 0, size = UIManager::getInstance()->getElements().size(); i < size; i++){
        UIManager::getInstance()->getElements()[i]->
            checkHover(Rectangle(0, 0, sizeTemp.x, sizeTemp.y), pos);
    }

    //update the active drag element
    if(UIManager::getInstance()->getDrag() != NULL){
        UIManager::getInstance()->getDrag()
            ->drag(UIManager::getInstance()->getLastButton());
    }
}

//updates ui on mouse press
//Input: void* data - pointer to the mouse button pressed
//Output: void
void uiMousePress(void* data){
    int button = *(int*)data;
    UIManager::getInstance()->setLastButton(button);

    for(int i = 0, size = UIManager::getInstance()->getElements().size(); i < size; i++){
        UIElement element = *UIManager::getInstance()->getElements()[i];

        if(element.focused){
            element.click(button);
            UIManager::getInstance()->setDrag(&element);
        }
    }
}

//updates ui on mouse release
//Input: void* data - pointer to the mouse button released
//Output: void
void uiMouseRelease(void* data){
    UIManager::getInstance()->setDrag(NULL);
}

//updates ui on window resize
//Input: void* data - pointer to the new window size
//Output: void
void uiWindowResize(void* data){
    Vector2 size = *(Vector2*)data;
    if(size.x == 0 || size.y == 0) return;
    UIManager::getInstance()->setSize(size);
}