#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "../library/opengl.h"
#include "../library/stb/stb_image.h"

#include "Shader.h"
#include "Vertex.h"
#include "VAO.h"
#include "VBO.h"
#include "Vertex.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, 
		GLenum format, GLenum pixelType, Vertex bounds);

	Texture(const char* image, Vertex bounds);
	
	//assigns texture unit to the texture
	void textUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
	GLfloat* getBounds();
	int getSize();
private:
	Vertex vertex;
};
#endif
