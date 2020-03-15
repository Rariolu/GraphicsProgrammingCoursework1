#include "GraphicsCourseworkScene.h"

void GraphicsCourseworkScene::Initialise()
{
	Scene::Initialise();
	GameObject* obj = AddGameObject(mario, texture1, tempShader);
	obj->SetPosition(0, -100, 300.0f);
}

bool GraphicsCourseworkScene::KeyDown(SDL_Keycode keycode)
{
	switch (keycode)
	{
		case SDLK_ESCAPE:
		{
			return false;
		}
		case SDLK_a:
		{
			camera->RotateY(rSpeed * DeltaTime());
			break;
		}
		case SDLK_d:
		{
			camera->RotateY(-rSpeed * DeltaTime());
			break;
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