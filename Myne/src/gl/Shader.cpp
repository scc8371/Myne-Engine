#include "Shader.h"

/// <summary>
/// returns file contents of a bin file passed in
/// </summary>
/// <param name="filename">file name of what is read, cstring</param>
/// <returns>string of file contents</returns>
std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary);
	try{
		//cheks if the file exists
		if (in) {
		//retrieves the file contents, stops at the end of the file.
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}

	throw(errno);
	}
	catch(int i){
		//if the file doesn't exist, throw an error
		std::cout << "problems reading file contents for shader!" << std::endl;
	}
	//error handling
	return " ";
}

// creates a shader object, loads the source, and compiles the shader
// inputs: location of the vertex shader (string), location of the fragment shader (string)
Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	//constructs the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	//constructs the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//enables alpha channel
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	//creates the shader program
	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

//activates the shader program
//inputs: none
//outputs: none
void Shader::Activate() {
	glUseProgram(ID);
}

//deletes the shader program
//inputs: none
//outputs: none
void Shader::Delete() {
	glDeleteProgram(ID);
}