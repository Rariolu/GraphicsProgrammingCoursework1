#include "ExplodingObject.h"

namespace GraphicsProgramming
{
	ExplodingObject::ExplodingObject(Mesh* mesh, ExplosionShader* shader, ModelTexture* texture) :
		GameObject(mesh, shader, texture)
	{
		Init(shader);
	}

	ExplodingObject* ExplodingObject::GetExplodingObject(string meshName, string shaderName, string textureName)
	{
		Mesh* mesh = rescManager->GetMesh(meshName);
		Shader* shader = rescManager->GetShader(shaderName);
		ModelTexture* texture = rescManager->GetModelTexture(textureName);
		ExplosionShader* eShader = nullptr;
		if (shader)
		{
			eShader = dynamic_cast<ExplosionShader*>(shader);
			eShader = new ExplosionShader(*eShader);
		}
		return new ExplodingObject(mesh, eShader, texture);
	}

	void ExplodingObject::Init(ExplosionShader* shader)
	{
		explosionShader = shader;
		SetExplosionMagnitude(magnitude);
		SphereCollider* sphereCollider = new SphereCollider(GetPosition(), 0.5f);
		SetCollider(sphereCollider);
	}

	void ExplodingObject::SetExploding(bool exp)
	{
		exploding = exp;
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
		exploding = !exploding;
		if (explosionShader)
		{
			explosionShader->SetExploding(exploding);
			//explosionShader->ToggleExploding();
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