#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "../library/opengl.h"
#include "../library/stb/stb_image.h"

#include "../gl/Shader.h"
#include "../gl/VAO.h"
#include "../gl/VBO.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, 
		GLenum format, GLenum pixelType);

	Texture(const char* image);
	
	//assigns texture unit to the texture
	void textUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
	GLfloat* getBounds();
	int getSize();
};
#endif
