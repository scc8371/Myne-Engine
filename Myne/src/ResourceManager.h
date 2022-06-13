#pragma once
#include <opengl/opengl.h>
#include "gl/Shader.h"
#include <ft2build.h>
#include FT_FREETYPE_H  
#include "gl/SpriteBatch.h"

class ResourceManager{
public:
    static ResourceManager* GetInstance();
    ~ResourceManager();
    void setWindow(GLFWwindow* window){ this->window = window; }
    GLFWwindow* getWindow() { return window; }

    void setShader(Shader* shader) {this->shader = shader; }
    Shader* getShader() {return shader; }

    FT_Library* getFt() {return ft;}

    void setSpriteBatch(SpriteBatch* spriteBatch) {this->spriteBatch = spriteBatch; }
    SpriteBatch* getSpriteBatch() {return spriteBatch;}

private:
    ResourceManager();
    GLFWwindow* window;
    Shader* shader;
    FT_Library* ft;  
    SpriteBatch* spriteBatch;
};
