#pragma once
#define GLFW_INCLUDE_NONE

#include <opengl/opengl.h>
#include <stb/stb_image.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>

#include "gl/SpriteBatch.h"
#include "gl/Shader.h"
#include "gl/VBO.h"
#include "gl/EBO.h"
#include "gl/VAO.h"
#include "texture/Texture.h"
#include "texture/TextureManager.h"
#include "ResourceManager.h"
#include "events/InputManager.h"
#include "events/EventManager.h"

#include <random>

class App
{
public:

	App();
	~App();
	
	static void resizeBuffer(Shader program);
	static void onResize(void* size);
	private:
	TextureManager* textureManager;
	InputManager* inputManager;
	EventManager* eventManager;		
};




