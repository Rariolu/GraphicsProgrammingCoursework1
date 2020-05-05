#include "SphereCollider.h"

namespace GraphicsProgramming
{

	SphereCollider::SphereCollider(Vec3* pos, float r, bool isDefaultRadius) : Collider(COLLIDERTYPE::SPHERE, pos)
	{
		radius = r;
		defaultRadius = isDefaultRadius ? r : 1.0f;
	}

	bool SphereCollider::CollidesWith(Collider* other)
	{
		//Checks if the other collider is a SphereCollider, 
		//and fully checks the collision if this is the case.
		switch (other->ColliderType())
		{
		case COLLIDERTYPE::SPHERE:
		{
			return CollidesWith((SphereCollider*)other);
		}
		}

		//Return false if the other collider is not a SphereCollider.
		return false;
	}

	bool SphereCollider::CollidesWith(SphereCollider* other)
	{
		//Get the positions of the two colliders.
		Vec3 pos = GetPosition();
		Vec3 otherPos = other->GetPosition();

		//Determine the sum of the two radii and square the value.
		float rSumSquared = SquareValue(other->GetRadius() + other->GetRadius());

		//Determine the square of the distance between the two positions.
		float dSquared = SquareValue(pos.x - otherPos.x) + SquareValue(pos.y - otherPos.y) + SquareValue(pos.z - otherPos.z);

		//If the square of the distance betweenb the positions is less than
		//or equal to the square of the sum of the radii, then a collision
		//has occurred.
		return dSquared <= rSumSquared;
	}

	float SphereCollider::GetRadius()
	{
		return radius;
	}

	void SphereCollider::SetRadius(float r)
	{
		radius = r;
	}

}