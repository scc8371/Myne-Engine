#include "EventManager.h"


EventManager::EventManager(){
    events = std::map<int, std::vector<Event>>(); 
    eventIDs = std::vector<int>();
}

EventManager* EventManager::getInstance(){
    static EventManager instance;
    return &instance;   
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS || GLFW_REPEAT){
        EventManager::getInstance()->sendEvent(KEYBOARD_PRESS, (void*)&key);
    }
}

void mouse_callback_move(GLFWwindow* window, double xPos, double yPos){
    Vector2 temp(xPos, yPos);

    EventManager::getInstance()->sendEvent(MOUSE_MOVED,
     (void*)&temp);
}

void mouse_callback_click(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        EventManager::getInstance()->
            sendEvent(MOUSE_PRESS, (void*)&button);
    }
}

void window_callback_resize(GLFWwindow* window, int width, int height){
    Vector2 temp(width, height);

    EventManager::getInstance()->
        sendEvent(WINDOW_RESIZE, (void*)&temp);
}

void EventManager::attachEvent(EventType type, Event event){
   
    //adds event to event list in the dict
    if(events.count(type.id)){
        events[type.id].push_back(event);
    }
    //adds new list to the dictionary
    else{
        std::vector<Event> eventsList;
        eventsList.push_back(event);
        events.emplace(type.id, eventsList);
    }
}

void EventManager::sendEvent(EventType type, void* data){
    if(events.count(type.id)){       
        for(int i = 0, size = events[type.id].size(); i < size; i++){
            events[type.id][i](data);
        }
    }
}

void EventManager::createCallbacks(GLFWwindow* window){
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback_move);
    glfwSetMouseButtonCallback(window, mouse_callback_click);
    glfwSetFramebufferSizeCallback(window, window_callback_resize);
}

EventType::EventType(int id){
    this->id = id;
}

   


