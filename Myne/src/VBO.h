#pragma once
#ifndef VBO_H
#define VBO_H

#ifndef IMPORTEDGL
#define IMPORTEDGL
#include "../../library/glad/glad.h"
#endif

class VBO {
public: 
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};
#endif