#include "CubeMap.h"

namespace GraphicsProgramming
{

	CubeMap::CubeMap(string facePath, string extension) :
		CubeMap(GetFacePaths(facePath, extension))
	{

	}

	CubeMap::CubeMap(string facePaths[faceNum])
	{
		glGenTextures(1, &textureHandler);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler);
		int width;
		int height;
		int nrChannels;
		for (unsigned int i = 0; i < faceNum; i++)
		{
			unsigned char* data = stbi_load(facePaths[i].c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			}
			else
			{
				Log("Cubemap texture failed to load at path: " + facePaths[i]);
			}
			stbi_image_free(data);

		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	}

	void CubeMap::Bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler);
	}

	string* CubeMap::GetFacePaths(string facePath, string extension)
	{
		return new string[6]
		{
			facePath + "_posX" + extension,
			facePath + "_negX" + extension,
			facePath + "_posY" + extension,
			facePath + "_negY" + extension,
			facePath + "_posZ" + extension,
			facePath + "_negZ" + extension
		};
	}

}