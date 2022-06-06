#pragma once
#include "../library/opengl.h"


struct Vertex
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

