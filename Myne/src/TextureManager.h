#pragma once
#include "Texture.h"
#include "VBO.h"
#include "VAO.h"
#include "Vertex.h"
#include <vector>

class TextureManager {

public:

	
	static TextureManager* getInstance();
	void addTexture(Texture texture, Shader shader);
	void removeTexture(Texture* texture);
	std::vector<Texture> getTextures();
	std::vector<VBO> getVBOS();
	void deleteTextures();
	void draw(VAO vao);
	

private:
	TextureManager();
	std::vector<Texture> textures;
	std::vector<VBO> vbos;
};
