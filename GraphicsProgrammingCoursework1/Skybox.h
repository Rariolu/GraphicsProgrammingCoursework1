#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "CubeMap.h"
#include "SkyBoxShader.h"

class SkyBox
{
	public:
		SkyBox(CubeMap* cubeMap, SkyBoxShader* shader);
		void Render();
		void SetCamera(Camera* _camera);
	private:
		Camera* camera;
		GLuint skyboxVAO;
		GLuint skyboxVBO;
		SkyBoxShader* skyboxShader;
		CubeMap* skyboxTexture;
		const float skyboxVertices[108] =
		{
			-6.0f, 6.0f, -6.0f,
			-6.0f, -6.0f, -6.0f,
			6.0f, -6.0f, -6.0f,
			6.0f, -6.0f, -6.0f,
			6.0f, 6.0f, -6.0f,
			-6.0f, 6.0f, -6.0f,
			-6.0f, -6.0f, 6.0f,
			-6.0f, -6.0f, -6.0f,
			-6.0f, 6.0f, -6.0f,
			-6.0f, 6.0f, -6.0f,
			-6.0f, 6.0f, 6.0f,
			-6.0f, -6.0f, 6.0f,
			6.0f, -6.0f, -6.0f,
			6.0f, -6.0f, 6.0f,
			6.0f, 6.0f, 6.0f,
			6.0f, 6.0f, 6.0f,
			6.0f, 6.0f, -6.0f,
			6.0f, -6.0f, -6.0f,
			-6.0f, -6.0f, 6.0f,
			-6.0f, 6.0f, 6.0f,
			6.0f, 6.0f, 6.0f,
			6.0f, 6.0f, 6.0f,
			6.0f, -6.0f, 6.0f,
			-6.0f, -6.0f, 6.0f,
			-6.0f, 6.0f, -6.0f,
			6.0f, 6.0f, -6.0f,
			6.0f, 6.0f, 6.0f,
			6.0f, 6.0f, 6.0f,
			-6.0f, 6.0f, 6.0f,
			-6.0f, 6.0f, -6.0f,
			-6.0f, -6.0f, -6.0f,
			-6.0f, -6.0f, 6.0f,
			6.0f, -6.0f, -6.0f,
			6.0f, -6.0f, -6.0f,
			-6.0f, -6.0f, 6.0f,
			6.0f, -6.0f, 6.0f
		};
};

#endif