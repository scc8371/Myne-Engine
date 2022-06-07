#include "EventManager.h"


EventManager::EventManager(){
    events = std::map<EventType, std::vector<Event>>();  
}

EventManager* EventManager::getInstance(){
    static EventManager instance;
    return &instance;   
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS || GLFW_REPEAT){
        EventManager::getInstance()->sendEvent(EventType::Keyboard_Press, (void*)&key);
    }
}

void mouse_callback_move(GLFWwindow* window, double xPos, double yPos){
    Vector2 temp(xPos, yPos);

    EventManager::getInstance()->sendEvent(EventType::Mouse_Moved,
     (void*)&temp);
}

void mouse_callback_click(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        EventManager::getInstance()->
            sendEvent(EventType::Mouse_Press, (void*)&button);
    }
}

void window_callback_resize(GLFWwindow* window, int width, int height){
    Vector2 temp(width, height);

    EventManager::getInstance()->
        sendEvent(EventType::Window_Resize, (void*)&temp);
}

void EventManager::attachEvent(EventType type, Event event){
   
    //adds event to event list in the dict
    if(events.count(type)){
        events[type].push_back(event);
    }
    //adds new list to the dictionary
    else{
        std::vector<Event> eventsList;
        eventsList.push_back(event);
        events.emplace(type, eventsList);

        for(int i = 0; i < eventsList.size(); i++){
        }
    }
}

void EventManager::sendEvent(EventType type, void* data){
    if(events.count(type)){        
        for(int i = 0, size = events[type].size(); i < size; i++){
            events[type][i](data);
        }
    }
}

void EventManager::createCallbacks(GLFWwindow* window){
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback_move);
    glfwSetMouseButtonCallback(window, mouse_callback_click);
    glfwSetFramebufferSizeCallback(window, window_callback_resize);
}


