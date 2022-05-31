#ifndef EBO_H
#define EBO_H

#include "../../library/glad/glad.h"

class EBO {
public:
	GLuint ID;
	EBO(GLuint* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif
