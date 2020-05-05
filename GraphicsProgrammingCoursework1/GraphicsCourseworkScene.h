#ifndef _GRAPHICS_COURSEWORK_SCENE_H
#define _GRAPHICS_COURSEWORK_SCENE_H

#include "Scene.h"
#include "Constants.h"
#include "ExplodingObject.h"
#include "ProjectileGameObject.h"

namespace GraphicsProgramming
{

	class GraphicsCourseworkScene : public Scene
	{
		public:
			void Initialise();
		private:
			void Fire();
			bool KeyDown(SDL_Keycode keycode);
			bool MouseDown(SDL_MouseButtonEvent mousebutton);
			bool Update();


			map<int, ProjectileGameObject*> projectiles;

			ExplodingObject* exploder;
			const float rSpeed = 5.0f;
			const float tSpeed = 20.0f;
	};

}

#endif