#include "Vertex.h"
#include <iostream>
Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat offset)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->offset = offset;
	size = 20;

	vertices = generateVertices();
}

Vertex::Vertex() : Vertex(1.0f, 1.0f, 0.0f, 0.5f) {}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat offset)
	: Vertex(x, y, 0.0f, offset) {}

GLfloat* Vertex::generateVertices()
{
	GLfloat* vertices = new GLfloat[]{ 
		x, y, z,								0.0f, 1.0f,
		x, y + (offset * 2), z,					0.0f, 0.0f,
		x + (offset * 2), y + (offset * 2), z,	1.0f, 0.0f,
		x + (offset * 2), y, z,					1.0f, 1.0f
	};

	std::cout << std::endl;

	return vertices;
}

GLfloat* Vertex::getVertexMatrix()
{
	return vertices;
}

int Vertex::getSize() {
	return size;
}
