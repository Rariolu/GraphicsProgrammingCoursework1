#include "GameObjectShader.h"

GameObjectShader::GameObjectShader(string vertFile, string fragFile) :
	Shader(vertFile,fragFile)
{

}

GameObjectShader::GameObjectShader(string geomFile, string vertFile, string fragFile) :
	Shader(geomFile,vertFile,fragFile)
{

}