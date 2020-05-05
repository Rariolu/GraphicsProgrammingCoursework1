#include "GameObjectShader.h"

namespace GraphicsProgramming
{

	GameObjectShader::GameObjectShader(string vertFile, string fragFile) :
		Shader(vertFile, fragFile)
	{

	}

	GameObjectShader::GameObjectShader(string geomFile, string vertFile, string fragFile) :
		Shader(geomFile, vertFile, fragFile)
	{

	}

	GameObjectShader::~GameObjectShader()
	{
		Shader::~Shader();
	}
}