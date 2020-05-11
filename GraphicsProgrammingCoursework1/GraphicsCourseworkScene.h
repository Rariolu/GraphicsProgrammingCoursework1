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
			void PostRender();
			bool Update();

			GameObjectManager projectiles;
			GameObjectManager exploders;
			FlakingObject* flaker;
			static const int instructionLength = 6;
			string instructions[instructionLength] =
			{
				"Press A to rotate anti-clockwise.",
				"Press D to rotate clockwise.",
				"Press W to move forwards.",
				"Press S to move backwards.",
				"Press space to fire projectile.",
				"Hit monkey head for it to explode."
			};
			int currentInstruction = 0;
			const float rSpeed = 5.0f;
			const float tSpeed = 20.0f;
	};

}

#endif