#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = NULL;

//returns the singleton instance of the resource manager
ResourceManager* ResourceManager::getInstance(){
    if(!instance) instance = new ResourceManager();
    return instance;
}

//Creates a new ResourceManager object, used within the singleton instance, shouldnt be called directly.
ResourceManager::ResourceManager()
{
    window = NULL;
    shader = NULL;
    ft = new FT_Library();    
}

//init ResourceManager
void ResourceManager::initialize(){
    fontShader = new Shader("resources/shader/default.vert", "resources/shader/fontShader.frag");
    shader = new Shader("resources/shader/default.vert", "resources/shader/default.frag");
}

//destructor to free resources
ResourceManager::~ResourceManager(){
    delete shader;
    delete ft;
    delete fontShader;
}
