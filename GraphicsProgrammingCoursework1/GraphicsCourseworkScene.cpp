#include "GraphicsCourseworkScene.h"

namespace GraphicsProgramming
{

	void GraphicsCourseworkScene::Initialise()
	{
		Scene::Initialise();
		GameObject* obj = AddGameObject(mario, texture1, tempShader);
		//obj->SetPosition(0, -100, 300.0f);
		obj->SetPosition(0, 0, 10);
		obj->Rotate(AXIS::Y, 180.0f);
	
		exploder = new ExplodingObject(mario, explosionShaderName, texture1);
		AddGameObject(exploder);
		
		exploder->SetPosition(0, 0, 5);

		SkyBox* sky = new SkyBox(skyboxFiles, skyboxShaderName);
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
				camera->Rotate(AXIS::Y, rSpeed * DeltaTime());
				break;
			}
			case SDLK_d:
			{
				camera->Rotate(AXIS::Y, -rSpeed * DeltaTime());
				break;
			}
			case SDLK_w:
			{
				camera->Translate((*camera->GetForward()) * DeltaTime() * tSpeed);
				break;
			}
			case SDLK_s:
			{
				camera->Translate((-(*camera->GetForward())) * DeltaTime() * tSpeed);
				break;
			}
			case SDLK_SPACE:
			{
				exploder->ToggleExploding();
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
		exploder->Update(DeltaTime());
		return true;
	}

}