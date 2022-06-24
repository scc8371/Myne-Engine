#pragma once
#include "Texture.h"
#include "../gl/VBO.h"
#include "../gl/VAO.h"
#include <vector>

class TextureManager {

public:	
	static TextureManager* getInstance();
	void addTexture(Texture texture, Shader shader);
	void removeTexture(Texture* texture);
	std::vector<Texture> getTextures();
	void deleteTextures();
	

private:
	TextureManager();
	std::vector<Texture> textures;
};
