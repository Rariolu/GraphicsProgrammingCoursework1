#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include "Aliases.h"

namespace GraphicsProgramming
{
	//Models

	const string mario = "Mario";
	const string marioFile = "..\\Resources\\Mario.obj";
	
	const string monkey = "monkey";
	const string monkeyFile = "..\\Resources\\monkey3.obj";

	const string ballMeshName = "ball";
	const string ballMeshFile = "..\\Resources\\ball.obj";

	//Textures

	const string texture1 = "joker";
	const string texture1File = "..\\Resources\\majora's mask.jpg";
	const string skyboxFiles = "..\\Resources\\skybox\\skybox";
	const string marioTextureName = "mario";
	const string marioTextureFile = "..\\Resources\\Mario.png";
	
	const string texture2 = "texture2";
	const string texture2File = "..\\Resources\\texture2.png";

	//Shaders

	const string tempShader = "tempShader";
	const string tempShaderVertFile = "..\\Resources\\quadMShader.vert";
	const string tempShaderFragFile = "..\\Resources\\quadMShader.frag";

	const string skyboxShaderName = "skybox";
	const string skyboxShaderVertFile = "..\\Resources\\skyboxShader.vert";
	const string skyboxShaderFragFile = "..\\Resources\\skyboxShader.frag";

	const string explosionShaderName = "explosionShader";
	const string explosionShaderVertFile = "..\\Resources\\explosionShader.vert";
	const string explosionShaderGeomFile = "..\\Resources\\explosionShader.geom";
	const string explosionShaderFragFile = "..\\Resources\\explosionShader.frag";

	const string purpleFlakeName = "purpleFlake";
	const string purpleFlakeVertFile = "..\\Resources\\purpleFlake.vert";
	const string purpleFlakeGeomFile = "..\\Resources\\purpleFlake.geom";
	const string purpleFlakeFragFile = "..\\Resources\\purpleFlake.frag";

	const string textShaderName = "textShader";
	const string textShaderVertFile = "..\\Resources\\TextShader.vert";
	const string textShaderFragFile = "..\\Resources\\TextShader.frag";

	//Fonts

	const string fontName = "arial";
	const string fontFile = "..\\Resources\\Fonts\\arial.ttf";

	//Scenes

	const string sceneName = "GraphicsCourseworkScene";

	//Window meta

	const string windowTitle = "GraphicsProgrammingCourseWork";
	const float windowWidth = 1024.0f;
	const float windowHeight = 768.0f;
}
#endif