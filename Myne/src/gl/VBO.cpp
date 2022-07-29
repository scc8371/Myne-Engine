#include "VBO.h"
#include <iostream>

//establishes a new VBO object, used in each texture to store data on the GPU
//inputs: GLfloat* vertices - the vertices to store in the VBO, GLsizeiptr size - the size of the vertices
//outputs: none
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

//default constructor
VBO::VBO(){
	glGenBuffers(1, &ID);
}

//binds the VBO
//inputs: none
//outputs: none
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

//unbinds the VBO
//inputs: none
//outputs: none
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//deletes the VBO
//inputs: none
//outputs: none
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
