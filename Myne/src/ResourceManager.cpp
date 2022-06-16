#include "ResourceManager.h"

//TODO: nuke this lol

ResourceManager* ResourceManager::instance = NULL;

ResourceManager* ResourceManager::GetInstance(){
    if(!instance) instance = new ResourceManager();
    return instance;
}

ResourceManager::ResourceManager()
{
    window = NULL;
    shader = NULL;
    ft = new FT_Library();    
}

void ResourceManager::initialize(){
    fontShader = new Shader("resources/shader/default.vert", "resources/shader/fontShader.frag");
    shader = new Shader("resources/shader/default.vert", "resources/shader/default.frag");
}

ResourceManager::~ResourceManager(){
    delete window;
    delete shader;
    delete ft;
    delete fontShader;
}
