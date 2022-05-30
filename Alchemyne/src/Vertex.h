#pragma once
#include "../../library/glad/glad.h"
#include "../../library/GLFW/include/GLFW/glfw3.h"
class Vertex
{
public:
	Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat offset);
	Vertex();
	Vertex(GLfloat x, GLfloat y, GLfloat offset);
	GLfloat* getVertexMatrix();
	int getSize();
private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat offset;

	GLfloat* vertices;
	int size;

	GLfloat* generateVertices();
	
	
};

