#include "ModelTexture.h"

ModelTexture::ModelTexture(string filename)
{
	int width;
	int height;
	int componentNumber;

	//Load image data from the given file name and store in "imageData".
	unsigned char* imageData = stbi_load(filename.c_str(), &width, &height, &componentNumber, 4);

	if (!imageData)
	{
		Log("Image from file \"" + filename + "\" failed to load.");
	}

	//Generate texture ID
	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_2D, textureHandler);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	//Free image data resources now that it's no longer required.
	stbi_image_free(imageData);
}

ModelTexture::~ModelTexture()
{
	//Delete the openGL texture
	glDeleteTextures(1, &textureHandler);
}

void ModelTexture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureHandler);
}