#include "EventManager.h"


EventManager::EventManager(){
    events = std::map<int, std::vector<Event>>(); 
    eventIDs = std::vector<int>();
}

//creates a new instance of the Event Manager singleton
//Inputs: none
//Outputs: EventManager singleton pointer
EventManager* EventManager::getInstance(){
    static EventManager instance;
    return &instance;   
}

//Event callback for when a key is pressed
//Inputs: Window pointer, integer code for the key pressed, integer code for the scancode,
//integer code for the action, integer code for the mods\
//Outputs: none
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS || GLFW_REPEAT){
        EventManager::getInstance()->sendEvent(KEYBOARD_PRESS, (void*)&key);
    }
}

//Event callback for when a mouse button is moved
//Inputs: Window pointer, double for the x position of the mouse, double for the y position of the mouse
//Outputs: none
void mouse_callback_move(GLFWwindow* window, double xPos, double yPos){
    Vector2 temp(xPos, yPos);

    EventManager::getInstance()->sendEvent(MOUSE_MOVED,
     (void*)&temp);
}

//Event callback for when the window is minimized, used to stop updates when the
//game is either minimized or not in focus
//Inputs: Window pointer, integer code for the minimized state
//Outputs: none
void window_minimize(GLFWwindow* window, int iconified){
    EventManager::getInstance()->sendEvent(WINDOW_MINIMIZE,
     (void*)&iconified);
}

//Event callback for when the mouse is clicked
//Inputs: Window pointer, integer code for the button pressed, integer code for the action, integer code for the mods
//Outputs: none
void mouse_callback_click(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        EventManager::getInstance()->
            sendEvent(MOUSE_PRESS, (void*)&button);
    }
}

//Event callback for when the window is resized
//Inputs: Window pointer, int values for the width and height of the window
//Outputs: none
void window_callback_resize(GLFWwindow* window, int width, int height){
    Vector2 temp(width, height);

    EventManager::getInstance()->
        sendEvent(WINDOW_RESIZE, (void*)&temp);
}

//Attaches an event to the list of current events stored in the event manager
//Inputs: EventType enum for the type of event (Defined by the event macro), and the event itself.
//Outputs: none
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

//Executes an event using data input from the user
//Inputs: EventType enum for the type of event (Defined by the event macro), and a void pointer to the data
//Outputs: none
void EventManager::sendEvent(EventType type, void* data){
    if(events.count(type.id)){       
        for(int i = 0, size = events[type.id].size(); i < size; i++){
            events[type.id][i](data);
        }
    }
}

//initializes GLFW callbacks
//inputs: Window pointer
//outputs: none
void EventManager::createCallbacks(GLFWwindow* window){
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback_move);
    glfwSetMouseButtonCallback(window, mouse_callback_click);
    glfwSetFramebufferSizeCallback(window, window_callback_resize);
    glfwSetWindowIconifyCallback(window, window_minimize);
}

//Creates a new EventType object; this is defined by the macro
//Inputs: int id for the event
//Outputs: EventType object
EventType::EventType(int id){
    this->id = id;
}

   


