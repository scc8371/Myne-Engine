#pragma once
#include "../ResourceManager.h"
#include "../utils/Vector2.h"
#include "EventManager.h"
// TRACKS ALL INPUT SENT FROM THE KEYBOARD AND MOUSE

class InputManager{
    public:
    static InputManager* GetInstance();
    Vector2 getMousePosition();

    private:
    InputManager();
};