#pragma once
#define GLFW_INCLUDE_NONE

#include <opengl/opengl.h>
#include <stb/stb_image.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <random>

#include "gl/SpriteBatch.h"
#include "gl/Shader.h"
#include "gl/VBO.h"
#include "gl/VAO.h"
#include "texture/Texture.h"
#include "texture/TextureManager.h"
#include "ResourceManager.h"
#include "events/InputManager.h"
#include "events/EventManager.h"
#include "sound/SoundManager.h"
#include "gl/SpriteBatch.h"
#include "Game.h"

#include "utils/Font.h"
#include <vector>

#include "ui/UIManager.h"



class App
{
public:

	static float window_y;
	static float window_x;

	App(Game* game);

	static Game* game;
	
	static void resizeBuffer(Shader* program);
	static void onResize(void* size);
	private:

	static void checkKbPress(void* data);
    static void checkKbRelease(void* data);
    static void checkMousePress(void* data);
    static void checkMouseRelease(void* data);

	float calcDt();
	float prevTime;
	float currTime;		
};




