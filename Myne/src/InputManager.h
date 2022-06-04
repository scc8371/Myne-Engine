#pragma once
#include "../library/GLFW/include/GLFW/glfw3.h"
#include "ResourceManager.h"
#include "Vector2.h"
#include "Event.h"
#include "KeyEvent.h"
// TRACKS ALL INPUT SENT FROM THE KEYBOARD AND MOUSE
class InputManager{
    public:
    static InputManager* GetInstance();
    bool isKeyPressed(int key);
    bool isMousePressed(int button);
    Vector2 getMousePosition();

    ~InputManager();

    private:
    InputManager();
    ResourceManager* resources;
};