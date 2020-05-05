#ifndef _PROJECTILEGAMEOBJECT_H
#define _PROJECTILEGAMEOBJECT_H

#include "GameObject.h"
#include "Constants.h"
#include "SphereCollider.h"

namespace GraphicsProgramming
{

	//A gameobject which collides using its spherical
	//volume and travels in a given direction until
	//it does so.
	class ProjectileGameObject : public GameObject
	{
		public:
			ProjectileGameObject();

			//Set the direction vector that the ball moves in.
			void SetDirection(Vec3 dir);

			//Set the scale of the gameobject and collider
			//bounds.
			void SetScale(float scale);

			//Move the ball in its given direction according
			//to the amount of time that has passed since the
			//last frame.
			void Update(float delta);

		private:
			//The direction vector that the projectile
			//will travel in.
			Vec3 direction;

			//A pointer to the current position of the projectile.
			Vec3* position;

			//The speed that the projectile travels in.
			const float speed = 8.0f;

			//The collider used to determine collisions
			//between this and other gameobjects.
			SphereCollider* sphereCollider;
	};

}

#endif