#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance(){
    static ResourceManager instance;
    return &instance;
}

ResourceManager::ResourceManager()
{
    window = NULL;
    shader = NULL;
    ft = new FT_Library();
}

ResourceManager::~ResourceManager(){
    delete window;
    delete shader;
    delete ft;
}
