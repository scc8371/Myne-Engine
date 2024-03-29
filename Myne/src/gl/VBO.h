#pragma once
#ifndef VBO_H
#define VBO_H
#endif

#include <glad/glad.h>

class VBO {
public: 
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO();

	void Bind();
	void Unbind();
	void Delete();
};
