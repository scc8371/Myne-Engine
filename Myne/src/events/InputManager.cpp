#include "InputManager.h"

InputManager::InputManager(){
    resources = ResourceManager::getInstance();
    events = EventManager::getInstance();
    //input setup goes here...
}

//returns singleton instance of the input manager.
InputManager* InputManager::GetInstance(){
    static InputManager instance;
    return &instance;
}

InputManager::~InputManager(){
    delete resources;
    delete events;
}

//returns the current position of the mouse as a Vector2.
//(x position, y position)
//takes projection matrix into account... returns pixel location not one that is bound to -1 to 1
Vector2 InputManager::getMousePosition(){
    double xPos, yPos;
    glfwGetCursorPos(resources->getWindow(), &xPos, &yPos);
    
    return Vector2((GLfloat)xPos, (GLfloat)yPos);
}