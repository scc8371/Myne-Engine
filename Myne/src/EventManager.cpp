#include "EventManager.h"
#include "ResourceManager.h"

EventManager* EventManager::getInstance(){
    static EventManager instance;
    return &instance;

    GLFWwindow* window = ResourceManager::GetInstance()->getWindow();

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback_move);
    glfwSetMouseButtonCallback(window, mouse_callback_click);
    glfwSetWindowSizeCallback(window, window_callback_resize);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
        if(action == GLFW_PRESS || GLFW_REPEAT){
            switch(key){
            case GLFW_KEY_W: 
                //jump
            break;

            case GLFW_KEY_S:
                //duck
            break;

            case GLFW_KEY_D:
                //right
            break;

            case GLFW_KEY_A:
                //left
            break;
        }
    }
}

void mouse_callback_move(GLFWwindow* window, double xPos, double yPos){
    //do thingys later idk 
}

void mouse_callback_click(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        switch(button){
            case GLFW_MOUSE_BUTTON_1:
                //do stuff with left click
            break;

            case GLFW_MOUSE_BUTTON_2:
                //do stuff with right click
            break;
        }
    }
}

void window_callback_resize(GLFWwindow* window, int width, int height){
    //do stuff lol
}


