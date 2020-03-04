#ifndef _MODELTEXTURE_H
#define _MODELTEXTURE_H

#include "stb_image.h"
#include "Aliases.h"
#include "glew.h"
#include "Logger.h"

//A class representing a single texture
//that's applied to a mesh. 
class ModelTexture
{
public:
	//Load a model texture from a given
	//file path.
	ModelTexture(string filename);
	~ModelTexture();

	//Bind the texture to the openGL buffer.
	void Bind();
private:

	//The unique ID of this texture.
	GLuint textureHandler;
};

#endif