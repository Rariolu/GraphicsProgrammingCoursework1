#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include "Shader.h"
#include "Camera.h"

namespace GraphicsProgramming
{

	class SkyBoxShader : public Shader
	{
	public:
		SkyBoxShader(string vertFile, string fragFile);
		void Bind(Camera* camera);
	};

}

#endif