#ifndef _MUTABLEPOINT_H
#define _MUTABLEPOINT_H

#include "Aliases.h"

enum class AXIS
{
	X, Y, Z
};

//A struct representing a specific object
//in 3D space which can be moved around
//(may add rotation later).
struct MutablePoint
{
	public:
		//Returns the address of the (x,y,z) position
		//of this point.
		virtual Vec3* GetPosition();

		//Sets the X, Y, and Z values of the position.
		virtual void SetPosition(float x, float y, float z);

		//Sets the X, Y, and Z values of the position.
		virtual void SetPosition(Vec3 position);

		//Add the given value to either the X, Y, or Z
		//position (depending on the given axis).
		virtual void Translate(AXIS axis, float a);

		virtual void Translate(Vec3 movement);
	protected:
		//The (x,y,z) position of this point.
		Vec3 position;
};

#endif