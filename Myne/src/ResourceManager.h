#pragma once
#include <opengl/opengl.h>
#include "gl/Shader.h"
#include <ft2build.h>
#include FT_FREETYPE_H  


class ResourceManager{
public:
    static ResourceManager* getInstance();
    ~ResourceManager();

    void setWindow(GLFWwindow* window){ this->window = window; }
    GLFWwindow* getWindow() { return window; }

    Shader* getShader() {return shader; }

    FT_Library* getFt() {return ft;}

    Shader* getFontShader(){ return fontShader; }

    void initialize();

private:
    static ResourceManager* instance;
    ResourceManager();
    GLFWwindow* window;
    Shader* shader;
    Shader* fontShader;
    FT_Library* ft;  
};
