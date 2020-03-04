#include "Collider.h"

Collider::Collider(COLLIDERTYPE type, Vec3* pos)
{
	colliderType = type;
	position = pos;
}

COLLIDERTYPE Collider::ColliderType()
{
	return colliderType;
}

Vec3 Collider::GetPosition()
{
	return *position;
}

Vec3* Collider::GetPositionPointer()
{
	return position;
}