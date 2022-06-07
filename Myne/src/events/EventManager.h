#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "../utils/Vector2.h"
#include "../ResourceManager.h"

enum EventType{
    Keyboard_Press, Keyboard_Release,
    Mouse_Press, Mouse_Release, Mouse_Moved,
    App_Update, App_Draw,
    Window_Resize, Window_Close,
    Game_Reset
};

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback_click(GLFWwindow* window, int button, int action, int mods);
void mouse_callback_move(GLFWwindow* window, double xPos, double yPos);
void window_callback_resize(GLFWwindow* window, int width, int height);

typedef void (*Event)(void*);

class EventManager{
    public:
        static EventManager* getInstance();

        void attachEvent(EventType type, Event);
        void sendEvent(EventType type, void* data);
        void createCallbacks(GLFWwindow* window);

    private:
        EventManager();
        std::map<EventType, std::vector<Event>> events;
};