#include "VBO.h"
#include <iostream>

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	for (int i = 1; i < 21; i++) {
		std::cout << vertices[i - 1] << " ";

		if (i % 5 == 0) {
			std::cout << std::endl;
		}
	}

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
