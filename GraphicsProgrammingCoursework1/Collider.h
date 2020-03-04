#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "Util.h"

//A value given to each derived class of 
//"Collider" to identify the type of 
//collider.
enum class COLLIDERTYPE
{
	SPHERE,
	BOX,
	OTHER
};

//A class which detects collisions with other colliders.
class Collider
{
public:
	Collider(COLLIDERTYPE type, Vec3* pos);

	//Returns true if a collision occurs between
	//this collider instance and the one given.
	//Left abstract because the nature of collision
	//depends on the particular collider type.
	virtual bool CollidesWith(Collider* other) = 0;

	//Get the collider type of this particular instance.
	COLLIDERTYPE ColliderType();

	//Get the value of the collider's current position.
	Vec3 GetPosition();

protected:
	//Return a pointer to the (x,y,z) location
	//of this collider.
	Vec3* GetPositionPointer();

private:
	//The collider type of this particular
	//instance.
	COLLIDERTYPE colliderType;
	//A pointer to the (x,y,z) location of this
	//collider.
	Vec3* position;
};

#endif