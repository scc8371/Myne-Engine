#include "App.h"


using namespace glm;

//window dimentions, can be changed.
int window_X = 1200;
int window_Y = 800;

App::App(Game* game) : game(*game)
{
	//dt stuff
	prevTime = 0.0f;
	currTime = 0.0f;

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
	if (window == NULL || game == NULL)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	//establishes buffer objects, binds and unbinds them respectively
	VAO VAO1;

	//texture stuff goes here...
	VAO1.Bind();

	eventManager->createCallbacks(window);

	SpriteBatch::GetInstance()->initialize();
	ResourceManager::GetInstance()->initialize();

	resizeBuffer(ResourceManager::GetInstance()->getShader());
	resizeBuffer(ResourceManager::GetInstance()->getFontShader());
	eventManager->attachEvent(EventType::Window_Resize, onResize);

	SpriteBatch* spriteBatch = SpriteBatch::GetInstance();	
	game->initialize();	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//rendering goes here
		float dt = calcDt();
		game->update(dt);	

		ResourceManager::GetInstance()->getShader()->Activate();
		game->draw(spriteBatch);
			
		spriteBatch->render();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	//deletes objects
	VAO1.Delete();
	textureManager->getInstance()->deleteTextures();
	ResourceManager::GetInstance()->getShader()->Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
}

//Resizes the window before anything is drawn to the screen.
//also handles projection (changes how the coordinate system is handled)
void App::resizeBuffer(Shader* program)
{
	glViewport(0, 0, window_X, window_Y);
	mat4x4 projection = ortho(0.0f, (float)window_X, (float)window_Y, 0.0f, 1.0f, -1.0f);

	program->Activate();
	GLuint projID = glGetUniformLocation(program->ID, "projection");

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

	window_X = windowSize.x;
	window_Y = windowSize.y;
	
	resizeBuffer(ResourceManager::GetInstance()->getShader());
	resizeBuffer(ResourceManager::GetInstance()->getFontShader());
}

//returns dt
float App::calcDt(){
	//dt
	prevTime = currTime;
	currTime = glfwGetTime();

	if(prevTime != 0){
		return currTime - prevTime;
	}
	else{
		return 0; 
	}
}

