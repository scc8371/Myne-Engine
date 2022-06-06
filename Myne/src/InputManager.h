#pragma once
#include "ResourceManager.h"
#include "Vector2.h"
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