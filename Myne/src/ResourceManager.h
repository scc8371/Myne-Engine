#pragma once
#include <opengl/opengl.h>
#include "gl/Shader.h"

class ResourceManager{
    public:
    static ResourceManager* GetInstance();
    
    void setWindow(GLFWwindow* window){ this->window = window; }
    GLFWwindow* getWindow() { return window; }

    void setShader(Shader* shader) {this->shader = shader; }
    Shader* getShader() {return shader; }

    private:
    ResourceManager();
    GLFWwindow* window;
    Shader* shader;
};
