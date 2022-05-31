#pragma once
#include "../library/GLFW/include/GLFW/glfw3.h"

class ResourceManager{
    public:
    static ResourceManager* GetInstance();
    void setWindow(GLFWwindow* window);
    GLFWwindow* getWindow();
    private:
    ResourceManager();
    GLFWwindow* window;
};