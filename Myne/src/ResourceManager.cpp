#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance(){
    static ResourceManager instance;
    return &instance;
}

ResourceManager::ResourceManager()
{
    window = NULL;
}

//sets the active window
void ResourceManager::setWindow(GLFWwindow* window){
    this->window = window;
}

//returns the active window
GLFWwindow* ResourceManager::getWindow(){
    return window;
}