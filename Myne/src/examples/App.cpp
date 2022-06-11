#include "App.h"
#include <vector>

using namespace glm;

//window dimentions, can be changed.
int window_X = 1200;
int window_Y = 800;

App::App()
{
	//manager classes.. handles what they describe respectively.
	textureManager = TextureManager::getInstance();
	inputManager = InputManager::GetInstance();
	eventManager = EventManager::getInstance();

	glfwInit();

	//lets compliler know which version of gl I am using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creates openGL window
	GLFWwindow* window = glfwCreateWindow(window_X, window_Y, "Myne Test Window", NULL, NULL);	
	//syncs window to resources
	ResourceManager::GetInstance()->setWindow(window);
	
	//terminates the GLFW 
	if (window == NULL)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	//creates shader program, must be activated when creating textures
	Shader shaderProgram("resources/default.vert", "resources/default.frag");
	ResourceManager::GetInstance()->setShader(&shaderProgram);
	resizeBuffer(shaderProgram);

	eventManager->attachEvent(EventType::Window_Resize, onResize);

	//establishes buffer objects, binds and unbinds them respectively
	VAO VAO1;

	//texture stuff goes here...
	VAO1.Bind();

	eventManager->createCallbacks(window);

	SpriteBatch spriteBatch;
	
	Texture bearger("resources/bearger.png");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//rendering goes here

		//sets the color of the window.
		glClearColor(0.15f, 0.115f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		for(int i = 1; i < 1000; i++){
			spriteBatch.draw(bearger, Rectangle(0, 0, 1, 1), Rectangle(1.5 * i, window_Y % i, 100, 100));
		}
		
		
		spriteBatch.render();

		glfwSwapBuffers(window);
		glfwPollEvents();

		// testing mouse position tracking
		Vector2 mousePos = inputManager->getMousePosition();
	}

	//deletes objects
	VAO1.Delete();
	textureManager->getInstance()->deleteTextures();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
}

//Resizes the window before anything is drawn to the screen.
//also handles projection (changes how the coordinate system is handled)
void App::resizeBuffer(Shader program)
{
	glViewport(0, 0, window_X, window_Y);
	mat4x4 projection = ortho(0.0f, (float)window_X, (float)window_Y, 0.0f, 1.0f, -1.0f);

	program.Activate();
	GLuint projID = glGetUniformLocation(program.ID, "projection");

	glUniformMatrix4fv(projID, 1, GL_FALSE, value_ptr(projection));
}

//frees memory when the program is terminated
App::~App(){
	delete inputManager;
	delete textureManager;
	delete eventManager;
}

void App::onResize(void* size){
	Vector2 windowSize = *(Vector2*)size;	

	window_X = windowSize.x();
	window_Y = windowSize.y();
	
	resizeBuffer(*ResourceManager::GetInstance()->getShader());
}

