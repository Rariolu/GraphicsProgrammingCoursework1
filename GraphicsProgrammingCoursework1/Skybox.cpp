#include "Skybox.h"

ResourceManager* SkyBox::resourceManager = ResourceManager::Instance();

SkyBox::SkyBox(string cubeMapPath, string shaderName) :
	SkyBox(new CubeMap(cubeMapPath,".png"),(SkyBoxShader*)resourceManager->GetShader(shaderName))
{

}

SkyBox::SkyBox(CubeMap* cubeMap, SkyBoxShader* shader)
{
	camera = nullptr;
	skyboxTexture = cubeMap;
	skyboxShader = shader;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void SkyBox::Render()
{
	if (camera)
	{
		glDepthFunc(GL_LEQUAL);

		skyboxShader->Bind(camera);
		skyboxTexture->Bind();

		glBindVertexArray(skyboxVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glDepthFunc(GL_LESS);
	}
}

void SkyBox::SetCamera(Camera* _camera)
{
	camera = _camera;
}