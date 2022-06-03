#include "App.h"
#include <vector>

using namespace glm;

//indices for a texture... should probably be moved in the future.
GLuint indices[] = {
		0, 2, 1,
		0, 3, 2
};

//window dimentions, can be changed.
const int WINDOW_X = 1200;
const int WINDOW_Y = 800;

App::App()
{
	//manager classes.. handles what they describe respectively.
	textureManager = TextureManager::getInstance();
	resourceManager = ResourceManager::GetInstance();
	inputManager = InputManager::GetInstance();

	glfwInit();

	//lets compliler know which version of gl I am using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creates openGL window
	GLFWwindow* window = glfwCreateWindow(WINDOW_X, WINDOW_Y, "Myne Test Window", NULL, NULL);
	//syncs window to resources
	resourceManager->setWindow(window);

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

	resizeBuffer(shaderProgram);

	//establishes buffer objects, binds and unbinds them respectively
	VAO VAO1;

	//texture stuff goes here...
	VAO1.Bind();

	//TEXTURE STUFF
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

		//testing mouse position tracking
		Vector2 mousePos = inputManager->getMousePosition();

		std::cout << mousePos.x() << ", " << mousePos.y() << std::endl;
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
	glViewport(0, 0, WINDOW_X, WINDOW_Y);
	mat4x4 projection = ortho(0.0f, (float)WINDOW_X, (float)WINDOW_Y, 0.0f, 1.0f, -1.0f);

	program.Activate();
	GLuint projID = glGetUniformLocation(program.ID, "projection");

	glUniformMatrix4fv(projID, 1, GL_FALSE, value_ptr(projection));
}

//frees memory when the program is terminated
App::~App(){
	delete inputManager;
	delete resourceManager;
	delete textureManager;
}


