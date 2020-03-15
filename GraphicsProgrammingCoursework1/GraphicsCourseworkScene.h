#ifndef _GRAPHICS_COURSEWORK_SCENE_H
#define _GRAPHICS_COURSEWORK_SCENE_H

#include "Scene.h"
#include "Constants.h"

class GraphicsCourseworkScene : public Scene
{
	public:
		void Initialise();
	private:
		bool KeyDown(SDL_Keycode keycode);
		bool MouseDown(SDL_MouseButtonEvent mousebutton);
		bool Update();
		const float rSpeed = 20.0f;
};

#endif