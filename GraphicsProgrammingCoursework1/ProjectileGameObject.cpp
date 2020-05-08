#include "ProjectileGameObject.h"

namespace GraphicsProgramming
{

	ProjectileGameObject::ProjectileGameObject() : GameObject(ballMeshName, tempShader, texture2)
	{
		//Retrieve a pointer to the gameobject's
		//position vector so that its translation
		//can be calculated when "Update" is called.
		position = GetPosition();
		const float ballScale = 0.05f;
		SetScale(ballScale);
	}

	void ProjectileGameObject::SetDirection(Vec3 dir)
	{
		direction = dir;
	}

	void ProjectileGameObject::SetScale(float scale)
	{
		GameObject::SetScale(Vec3(scale, scale, scale));
		if (sphereCollider)
		{
			sphereCollider->SetRadius(scale);
		}
		else
		{
			sphereCollider = new SphereCollider(position, scale);
		}

		SetCollider(sphereCollider);
	}

	void ProjectileGameObject::Update(float delta)
	{
		//travel quantity = speed * delta
		//velocity = direction * travel quantity
		//New Position = Current position + velocity
		SetPosition((*position) + (direction * (speed * delta)));
	}

}