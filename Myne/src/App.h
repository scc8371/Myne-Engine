#pragma once
#define GLFW_INCLUDE_NONE

#include "../library/opengl.h"
#include "../../library/stb/stb_image.h"

#include "../../library/glm/vec3.hpp" // glm::vec3
#include "../../library/glm/vec4.hpp" // glm::vec4
#include "../../library/glm/mat4x4.hpp" // glm::mat4
#include "../../library/glm/gtc/matrix_transform.hpp" // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "../../library/glm/gtc/type_ptr.hpp"

#include "Shader.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"
#include "Texture.h"
#include "Vertex.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "EventManager.h"

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




