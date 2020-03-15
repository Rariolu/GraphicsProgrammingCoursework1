#include "GraphicsCourseworkScene.h"

void GraphicsCourseworkScene::Initialise()
{
	Scene::Initialise();
	GameObject* obj = AddGameObject(mario, texture1, tempShader);
	obj->SetPosition(0, -100, 300.0f);
	SkyBox* sky = new SkyBox(skyboxFiles2, skyboxShaderName);
	SetSkyBox(sky);
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
			camera->Rotate(AXIS::Y,rSpeed * DeltaTime());
			break;
		}
		case SDLK_d:
		{
			camera->Rotate(AXIS::Y,-rSpeed * DeltaTime());
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