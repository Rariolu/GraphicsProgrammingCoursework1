#include "FlakingObject.h"

namespace GraphicsProgramming
{
	FlakingObject::FlakingObject(Mesh* mesh, PurpleFlakeShader* shader, ModelTexture* texture)
		:GameObject(mesh,shader,texture)
	{
		Init(shader);
	}

	FlakingObject* FlakingObject::GetFlakingObject(string meshName, string shaderName, string textureName)
	{
		Mesh* mesh = rescManager->GetMesh(meshName);
		Shader* shader = rescManager->GetShader(shaderName);
		ModelTexture* texture = rescManager->GetModelTexture(textureName);
		PurpleFlakeShader* pfShader = nullptr;
		if (shader)
		{
			pfShader = dynamic_cast<PurpleFlakeShader*>(shader);
			pfShader = new PurpleFlakeShader(*pfShader);
		}
		return new FlakingObject(mesh, pfShader, texture);
	}

	void FlakingObject::Update(float delta)
	{
		if (purpleFlakeShader)
		{
			purpleFlakeShader->IncreaseTime(delta);
		}
	}

	void FlakingObject::Init(PurpleFlakeShader* pfShader)
	{
		purpleFlakeShader = pfShader;
	}
}