#include "InputManager.h"

InputManager::InputManager(){
    resources = ResourceManager::GetInstance();
    //input setup goes here...
}

//returns singleton instance of the input manager.
InputManager* InputManager::GetInstance(){
    static InputManager instance;
    return &instance;
}

InputManager::~InputManager(){
    delete resources;
}

//returns true if a key is pressed down or held
bool InputManager::isKeyPressed(int key){
    auto state = glfwGetKey(resources->getWindow(), key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

//returns true if a specific button is held down.
bool InputManager::isMousePressed(int button){
    auto state = glfwGetMouseButton(resources->getWindow(), button);
    return state == GLFW_PRESS;
}

//returns the current position of the mouse as a Vector2.
//(x position, y position)
//takes projection matrix into account... returns pixel location not one that is bound to -1 to 1
Vector2 InputManager::getMousePosition(){
    double xPos, yPos;
    glfwGetCursorPos(resources->getWindow(), &xPos, &yPos);
    
    return Vector2((GLfloat)xPos, (GLfloat)yPos);
}