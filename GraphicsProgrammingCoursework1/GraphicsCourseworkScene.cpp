#include "GraphicsCourseworkScene.h"

bool GraphicsCourseworkScene::KeyDown(SDL_Keycode keycode)
{
	switch (keycode)
	{
		case SDLK_ESCAPE:
		{
			return false;
		}
	}
	return true;
}

bool GraphicsCourseworkScene::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	return true;
}


bool GraphicsCourseworkScene::Update()
{
	return true;
}