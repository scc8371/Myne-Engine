#pragma once
#include "../../library/glad/glad.h"
#include "../../library/GLFW/include/GLFW/glfw3.h"
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


class App
{
public:
	App();
private:
	TextureManager* textureManager;
	void resizeBuffer(Shader program);
};

