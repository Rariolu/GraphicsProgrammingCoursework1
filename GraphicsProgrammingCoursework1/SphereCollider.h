#ifndef _SPHERECOLLIDER_H
#define _SPHERECOLLIDER_H

#include "Aliases.h"
#include "Collider.h"

namespace GraphicsProgramming
{

	//A collider which detects collisions within
	//its spherical shape.
	class SphereCollider : public Collider
	{
		public:
			SphereCollider(Vec3* pos, float r, bool isDefaultRadius = false);

			//Determines whether or not this collider
			//collides with another, will only detect
			//collisions with other sphere colliders.
			bool CollidesWith(Collider* other);

			//Determines whether this sphere collider
			//collides with another sphere collider
			//by comparing the distance between them
			//and their respective radii.
			bool CollidesWith(SphereCollider* other);

			//Return the radius of this sphere's bounds.
			float GetRadius();

			//Set the radius of this sphere's bounds.
			void SetRadius(float r);

		private:
			//The default radius of the sphere, used to accurately
			//apply scale in order to create a new radius.
			float defaultRadius;

			//The radius of the sphere's bounds. Collisions
			//only occur if the other collider intersects with an area
			//within this distance of the collider's position.
			float radius;
	};

}

#endif