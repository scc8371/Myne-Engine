#include "App.h"
#include <vector>

using namespace glm;

//indices for a texture... should probably be moved in the future.
GLuint indices[] = {
		0, 2, 1,
		0, 3, 2
};

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

	//TEXTURE LOADING
	try{
		textureManager->addTexture(Texture("resources/bearger.png", 
			Vertex(20.0f, 20.0f, 100.0f)), shaderProgram);

		textureManager->addTexture(Texture("resources/bearger.png", 
			Vertex(500.0f, 20.0f, 600.0f)), shaderProgram);
	}	
	catch(int i){
		std::cout << "Textures not loaded properly." << std::endl;
	}
	
	EBO EBO1(indices, sizeof(indices));

	VAO1.Unbind();

	eventManager->createCallbacks(window);
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//rendering goes here

		//sets the color of the window.
		glClearColor(0.15f, 0.115f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		textureManager->getInstance()->draw(VAO1);

		glfwSwapBuffers(window);
		glfwPollEvents();

		// testing mouse position tracking
		Vector2 mousePos = inputManager->getMousePosition();

		//std::cout << mousePos.x() << ", " << mousePos.y() << std::endl;
	}

	//deletes objects
	VAO1.Delete();
	EBO1.Delete();
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
	std::cout << "Resized" << std::endl;
}

