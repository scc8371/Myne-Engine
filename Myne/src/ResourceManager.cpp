#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance(){
    static ResourceManager instance;
    return &instance;
}

ResourceManager::ResourceManager()
{
    window = NULL;
    shader = NULL;
    ft = NULL;
}
