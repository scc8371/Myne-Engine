#pragma once

#include "Event.h"
#include <iostream>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback_click(GLFWwindow* window, int button, int action, int mods);
void mouse_callback_move(GLFWwindow* window, double xPos, double yPos);
void window_callback_resize(GLFWwindow* window, int width, int height);

class EventManager{
    public:
        static EventManager* getInstance();

    private:
        EventManager();
        
};
