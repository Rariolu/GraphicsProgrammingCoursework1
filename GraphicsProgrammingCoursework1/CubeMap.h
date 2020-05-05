#ifndef _CUBEMAP_H
#define _CUBEMAP_H

#include "glew.h"
#include "Aliases.h"
#include "stb_image.h"
#include "Logger.h"

namespace GraphicsProgramming
{

	class CubeMap
	{
		private:
			const static unsigned int faceNum = 6;
		public:
			CubeMap(string facePath, string extension);
			CubeMap(string facePaths[faceNum]);
			void Bind();
		private:
			string* GetFacePaths(string facePath, string extension);
			GLuint textureHandler;

	};

}

#endif