#ifndef _GRAPHICS_COURSEWORK_SCENE_H
#define _GRAPHICS_COURSEWORK_SCENE_H

#include "Scene.h"
#include "Constants.h"
#include "ExplodingObject.h"
#include "ProjectileGameObject.h"
#include "FlakingObject.h"

namespace GraphicsProgramming
{

	class GraphicsCourseworkScene : public Scene
	{
		public:
			void Initialise();
			void Dispose();
		private:
			void DestroyProjectile(ProjectileGameObject* ball);
			void Fire();
			bool KeyDown(SDL_Keycode keycode);
			bool MouseDown(SDL_MouseButtonEvent mousebutton);
			bool Update();

			GameObjectManager projectiles;
			GameObjectManager exploders;
			FlakingObject* flaker;

			const float rSpeed = 5.0f;
			const float tSpeed = 20.0f;
	};

}

#endif