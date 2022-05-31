#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance(){
    static ResourceManager instance;
    return &instance;
}

ResourceManager::ResourceManager()
{
    window = NULL;
}

void ResourceManager::setWindow(GLFWwindow* window){
    this->window = window;
}

GLFWwindow* ResourceManager::getWindow(){
    return window;
}