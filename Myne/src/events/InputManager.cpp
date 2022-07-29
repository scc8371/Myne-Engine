#include "InputManager.h"

InputManager::InputManager(){}

//returns singleton instance of the input manager.
InputManager* InputManager::GetInstance(){
    static InputManager instance;
    return &instance;
}

//returns the current position of the mouse as a Vector2.
//(x position, y position)
//takes projection matrix into account... returns pixel location not one that is bound to -1 to 1
Vector2 InputManager::getMousePosition(){
    double xPos, yPos;
    glfwGetCursorPos(ResourceManager::getInstance()->getWindow(), &xPos, &yPos);
    
    return Vector2((GLfloat)xPos, (GLfloat)yPos);
}