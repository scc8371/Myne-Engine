#include "TextureManager.h"

TextureManager::TextureManager() {
	textures = std::vector<Texture>();
}

//returns an instance of the singleton TextureManager
//inputs: none
//outputs: TextureManager* - pointer to the singleton TextureManager
TextureManager* TextureManager::getInstance()
{
	static TextureManager instance;
	return &instance;
}

/// <summary>
/// adds a texture to the global texture list.
/// </summary>
/// <param name="texture">texture that is added to the list</param>
void TextureManager::addTexture(Texture texture, Shader shader)
{
	textures.push_back(texture);

	texture.textUnit(shader, "tex0", 0);
}

//deletes a texture from the list of active textures.. 
//this method is not tested... will probably need to be tested before implementation
void TextureManager::removeTexture(Texture* texture)
{
	for (int i = 0, size = textures.size(); i < size; i++) {
		if (&textures[i] == texture) {
			textures.erase(textures.begin() + i);
		}
	}
}

//returns the list of textures
std::vector<Texture> TextureManager::getTextures()
{
	return textures;
}

//deletes all textures in the texture manager singleton
void TextureManager::deleteTextures()
{
	for (int i = 0, size = textures.size(); i < size; i++) {
		textures[i].Delete();
	}
}
