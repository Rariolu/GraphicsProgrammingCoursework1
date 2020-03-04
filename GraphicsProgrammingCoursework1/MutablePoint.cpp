#include "MutablePoint.h"

Vec3* MutablePoint::GetPosition()
{
	return &position;
}

void MutablePoint::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void MutablePoint::SetPosition(Vec3 position)
{
	SetPosition(position.x, position.y, position.z);
}

void MutablePoint::Translate(AXIS axis, float a)
{
	switch (axis)
	{
		case AXIS::X:
		{
			SetPosition(position.x + a, position.y, position.z);
			break;
		}
		case AXIS::Y:
		{
			SetPosition(position.x, position.y + a, position.z);
			break;
		}
		case AXIS::Z:
		{
			SetPosition(position.x, position.y, position.z + a);
			break;
		}
	}
}