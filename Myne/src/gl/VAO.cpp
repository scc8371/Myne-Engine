#include "VAO.h"

//establishes a new VAO object, used to render a batch of sprites to the screen (see SpriteBatch) -> you shouldnt need many at once.
//inputs: none
//outputs: none
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

//links attributes to the VAO
//inputs: VBO - the VBO to link to the VAO, 
//        GLuint layout - the layout of the VAO (0 for position, 1 for UV, 2 for color)
//        GLuint numComponents - the number of components in the VAO
//        GLenum type - the type of data in the VAO
//        GLsizeiptr stride - the stride of the VAO
//        void* offset - the offset of the VAO 
void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

//binds the VAO
//inputs: none
//outputs: none
void VAO::Bind()
{
	glBindVertexArray(ID);
}

//unbinds the VAO
//inputs: none
//outputs: none
void VAO::Unbind()
{
	glBindVertexArray(0);
}

//deletes the VAO
//inputs: none
//outputs: none
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
