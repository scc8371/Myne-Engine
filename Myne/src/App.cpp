#include "App.h"


using namespace glm;

//window dimentions, can be changed.
float App::window_x = 1200;
float App::window_y = 800;

bool App::isUpdating = true;

Game* App::game = NULL;

//initializes main aspects of the game
App::App(Game* game)
{
	this->game = game;
	//dt stuff
	prevTime = 0.0f;
	currTime = 0.0f;

	glfwInit();
	
	//lets compliler know which version of gl I am using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creates openGL window
	GLFWwindow* window = glfwCreateWindow(App::window_x, App::window_y, "Myne Test Window", NULL, NULL);	
	//syncs window to resources]
	ResourceManager::getInstance()->setWindow(window);
	
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

	EventManager::getInstance()->createCallbacks(window);

	SpriteBatch::getInstance()->initialize();
	ResourceManager::getInstance()->initialize();
	SoundManager::getInstance()->initialize();

	resizeBuffer(ResourceManager::getInstance()->getShader());
	resizeBuffer(ResourceManager::getInstance()->getFontShader());
	EventManager::getInstance()->attachEvent(WINDOW_RESIZE, onResize);

	//input events
	EventManager::getInstance()->attachEvent(KEYBOARD_PRESS, checkKbPress);
	EventManager::getInstance()->attachEvent(KEYBOARD_RELEASE, checkKbRelease);
	EventManager::getInstance()->attachEvent(MOUSE_PRESS, checkMousePress);
	EventManager::getInstance()->attachEvent(MOUSE_RELEASE, checkMouseRelease);
	EventManager::getInstance()->attachEvent(WINDOW_MINIMIZE, onMinimize);

	SpriteBatch* spriteBatch = SpriteBatch::getInstance();	
	game->initialize();	

	//resizes for UI
	Vector2 windowSize = Vector2(window_x, window_y);
	EventManager::getInstance()->sendEvent(WINDOW_RESIZE, &windowSize);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		float dt = calcDt();

		if(isUpdating){
			//rendering goes here
			game->update(dt);	
			UIManager::getInstance()->updateUI(dt); 
			SoundManager::getInstance()->updateAudio();
		}	

		ResourceManager::getInstance()->getShader()->Activate();
		game->draw(spriteBatch);
		UIManager::getInstance()->drawUI();	
		spriteBatch->render();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	game->onClose();

	//deletes objects
	VAO1.Delete();
	TextureManager::getInstance()->deleteTextures();
	ResourceManager::getInstance()->getShader()->Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
}

//changes the window name
//inputs: new window name
//outputs: none
void App::changeTitle(const char* title)
{
	glfwSetWindowTitle(ResourceManager::getInstance()->getWindow(), title);
}

//changes the window icon of the game
//inputs: const char* path: the path to the icon
//outputs: none
void App::changeIcon(const char* path){
	GLFWimage images[1];
	images[0].pixels = stbi_load(path, &images[0].width, &images[0].height, 0, 4);
	glfwSetWindowIcon(ResourceManager::getInstance()->getWindow(), 1, images);
	stbi_image_free(images[0].pixels);
}
//Resizes the window before anything is drawn to the screen.
//also handles projection (changes how the coordinate system is handled)
void App::resizeBuffer(Shader* program)
{
	glViewport(0, 0, App::window_x, window_y);
	mat4x4 projection = ortho(0.0f, (float)window_x, (float)window_y, 0.0f, 1.0f, -1.0f);

	program->Activate();
	GLuint projID = glGetUniformLocation(program->ID, "projection");

	glUniformMatrix4fv(projID, 1, GL_FALSE, value_ptr(projection));
}

//Event function that stops the game from updating when the window is minimized
//inputs: void* data: the data that is sent to the function
//outputs: none
void App::onMinimize(void* data)
{
	if(*(int*)data){
		isUpdating = false;
	}
	else if(!*(int*)data){
		isUpdating = true;
	}
}

//puts the window in fullscreen mode
//inputs: bool fullscreen: if the window is fullscreen or not
//outputs: none
void App::fullscreen(bool fullscreen)
{
	//true value supplimented - fullscreen
	if(fullscreen){
		glfwSetWindowMonitor(ResourceManager::getInstance()->getWindow(), glfwGetPrimaryMonitor(), 0, 0, window_x, window_y, 0);
	}
	//sets back to windowed
	else{
		glfwSetWindowMonitor(ResourceManager::getInstance()->getWindow(), NULL, 0, 0, window_x, window_y, 0);
	}
}

//Event function that properly resizes everything rendered to the screen when the window is resized
//inputs: void* data: the data that is sent to the function
//outputs: none
void App::onResize(void* size){
	Vector2 windowSize = *(Vector2*)size;	

	App::window_x = windowSize.x;
	App::window_y = windowSize.y;
	
	resizeBuffer(ResourceManager::getInstance()->getShader());
	resizeBuffer(ResourceManager::getInstance()->getFontShader());
}

//Event function that checks if a key is pressed
//inputs: void* data: the data that is sent to the function
//outputs: none
void App::checkKbPress(void* data){
	App::game->kbPress((int*)data);
}

//Event function that checks if a key is released
//inputs: void* data: the data that is sent to the function
//outputs: none
void App::checkKbRelease(void* data){
	App::game->kbRelease((int*)data);
}

//Event function that checks if a mouse button is pressed
//inputs: void* data: the data that is sent to the function
//outputs: none
void App::checkMousePress(void* data){
	App::game->mousePress((int*)data);
}

//checks if the mouse is released
//inputs: data - mouse button
//outputs: none
void App::checkMouseRelease(void* data){
	App::game->mouseRelease((int*)data);
}

//returns dt
//inputs: none
//outputs: float - dt
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

