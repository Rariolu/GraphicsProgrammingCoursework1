#include "SkyBoxShader.h"

SkyBoxShader::SkyBoxShader(string vertFile, string fragFile) :
	Shader(vertFile,fragFile)
{

}

void SkyBoxShader::Bind(Camera* camera)
{
	Shader::Bind();
	SetInt("skybox", 0);
	SetMatrix("view",RemoveTranslation(camera->GetView()));
	SetMatrix("projection", camera->GetProjection());
}