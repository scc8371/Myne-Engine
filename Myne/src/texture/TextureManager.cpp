#include "TextureManager.h"

TextureManager::TextureManager() {
	textures = std::vector<Texture>();
	vbos = std::vector<VBO>();
}

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
	vbos.push_back(VBO(texture.getBounds(),
		sizeof(texture.getBounds()) * texture.getSize()));

	texture.textUnit(shader, "tex0", 0);
}

//deletes a texture from the list of active textures.. 
//this method is not tested... will probably need to be tested before implementation
void TextureManager::removeTexture(Texture* texture)
{
	for (int i = 0, size = textures.size(); i < size; i++) {
		if (&textures[i] == texture) {
			textures.erase(textures.begin() + i);
			vbos.erase(vbos.begin() + i);
		}
	}
}

//returns the list of textures
std::vector<Texture> TextureManager::getTextures()
{
	return textures;
}

//returns the list of active VBOS
std::vector<VBO> TextureManager::getVBOS()
{
	return vbos;
}

//deletes all textures in the texture manager singleton
void TextureManager::deleteTextures()
{
	for (int i = 0, size = textures.size(); i < size; i++) {
		textures[i].Delete();
		vbos[i].Delete();
	}
}

//draws all active textures in the textures vertex array
void TextureManager::draw(VAO vao)
{
	for (int i = 0, size = textures.size(); i < size; i++) {
		//sets num of channels and designates shader information
		vao.LinkAttrib(vbos[i], 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
		vao.LinkAttrib(vbos[i], 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

		textures[i].Bind();
		vao.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}
