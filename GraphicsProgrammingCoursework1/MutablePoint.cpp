#include "MutablePoint.h"

namespace GraphicsProgramming
{

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
		float x = (axis == AXIS::X) * a;
		float y = (axis == AXIS::Y) * a;
		float z = (axis == AXIS::Z) * a;
		Translate(Vec3(x, y, z));
		//switch (axis)
		//{
		//	case AXIS::X:
		//	{
		//		SetPosition(position.x + a, position.y, position.z);
		//		break;
		//	}
		//	case AXIS::Y:
		//	{
		//		SetPosition(position.x, position.y + a, position.z);
		//		break;
		//	}
		//	case AXIS::Z:
		//	{
		//		SetPosition(position.x, position.y, position.z + a);
		//		break;
		//	}
		//}
	}

	void MutablePoint::Translate(Vec3 movement)
	{
		position += movement;
	}

}