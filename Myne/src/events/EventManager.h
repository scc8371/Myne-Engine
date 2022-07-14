#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "../utils/Vector2.h"
#include "../ResourceManager.h"

#define CREATE_EVENT(EVENT_NAME, ID) \
    static const EventType EVENT_NAME = EventType(ID);

class EventType{
public:
    EventType(int id);
    int id;
};

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback_click(GLFWwindow* window, int button, int action, int mods);
void mouse_callback_move(GLFWwindow* window, double xPos, double yPos);
void window_callback_resize(GLFWwindow* window, int width, int height);
void window_minimize(GLFWwindow* window, int iconified);
typedef void (*Event)(void*);

class EventManager{
    public:
        static EventManager* getInstance();

        void attachEvent(EventType type, Event);
        void sendEvent(EventType type, void* data);
        void createCallbacks(GLFWwindow* window);

    private:
        EventManager();
        std::map<int, std::vector<Event>> events;
        std::vector<int> eventIDs;
};

CREATE_EVENT(KEYBOARD_PRESS, 1);
CREATE_EVENT(KEYBOARD_RELEASE, 2);
CREATE_EVENT(MOUSE_MOVED, 3); 
CREATE_EVENT(MOUSE_PRESS, 4);
CREATE_EVENT(MOUSE_RELEASE, 5);
CREATE_EVENT(WINDOW_RESIZE, 6);
CREATE_EVENT(WINDOW_MINIMIZE, 7);

