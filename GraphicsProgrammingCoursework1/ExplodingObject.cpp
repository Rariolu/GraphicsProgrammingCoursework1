#include "ExplodingObject.h"

namespace GraphicsProgramming
{

	ExplodingObject::ExplodingObject(string meshName, string shaderName, string textureName)
		: GameObject(meshName, shaderName, textureName)
	{
		Shader* shader = rescManager->GetShader(shaderName);
		//Init((ExplosionShader*)shader);
		if (shader)
		{
			ExplosionShader* explosionShader;
			if (explosionShader = dynamic_cast<ExplosionShader*>(shader))
			{
				Init(explosionShader);
			}
		}
	}

	ExplodingObject::ExplodingObject(Mesh* mesh, ExplosionShader* shader, ModelTexture* texture) :
		GameObject(mesh, shader, texture)
	{
		Init(shader);
	}

	void ExplodingObject::Init(ExplosionShader* shader)
	{
		explosionShader = shader;
		SetExplosionMagnitude(magnitude);
	}

	void ExplodingObject::SetExploding(bool exp)
	{
		if (explosionShader)
		{
			explosionShader->SetExploding(exp);
		}
	}

	void ExplodingObject::SetExplosionMagnitude(float mag)
	{
		magnitude = mag;
		if (explosionShader)
		{
			explosionShader->SetExplosionMagnitude(mag);
		}
	}

	void ExplodingObject::ToggleExploding()
	{
		if (explosionShader)
		{
			explosionShader->ToggleExploding();
		}
	}

	void ExplodingObject::Update(float delta)
	{
		if (explosionShader)
		{
			explosionShader->IncreaseTime(delta);
		}
	}

}