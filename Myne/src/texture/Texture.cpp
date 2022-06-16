#include "Texture.h"
Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	type = texType;

	int imgWidth;
	int imgHeight;
	int numColorChannels;

	unsigned char* bytes = stbi_load(image, &imgWidth, &imgHeight, &numColorChannels, 0);

	//generates texture object
	glGenTextures(1, &ID);

	glActiveTexture(slot);
	glBindTexture(texType, ID);

	//Configures image resizing
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//configures repeating textures
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//assigns texture to the OpenGL texture object
	glTexImage2D(texType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);
	glGenerateMipmap(texType);

	//we no longer need the image data, free it...
	stbi_image_free(bytes);

	//Unbinds openGL texture so we cannot accidentally modify it.
	glBindTexture(texType, 0);
}

Texture::Texture(const char* image)
	: Texture(image, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE) {}

Texture::Texture(){}

Texture::Texture(int width, int height){
	type = GL_TEXTURE_2D;
	
	glActiveTexture(GL_TEXTURE0);	
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	//Configures image resizing
	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//configures repeating textures
	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

	glGenerateMipmap(type);

	//Unbinds openGL texture so we cannot accidentally modify it.
	glBindTexture(type, 0);
}

void Texture::textUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);

	//need to activate the shader before changing value of a uniform
	shader.Activate();

	//sets value of the uniform
	glUniform1f(texUni, unit);
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
