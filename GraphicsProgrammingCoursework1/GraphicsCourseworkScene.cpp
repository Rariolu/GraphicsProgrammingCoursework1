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

	void GraphicsCourseworkScene::DestroyProjectile(ProjectileGameObject* ball)
	{
		projectiles.RemoveGameObject(ball);
		RemoveGameObject(ball);
		//map<int, ProjectileGameObject*>::iterator iter = projectiles.find((int)ball);
		//if (iter != projectiles.end())
		//{
		//	projectiles.erase(iter);
		//	RemoveGameObject(ball);
		//}
	}

	void GraphicsCourseworkScene::Fire()
	{
		//Instantiate a projectile
		ProjectileGameObject* ball = new ProjectileGameObject();

		//Set the direction of the projectile according to the
		//camera's orientation.
		Vec3* forward = camera->GetForward();
		ball->SetDirection(*forward);

		//Set the initial position of the projectile to be offset
		//from the camera's position.
		const float d = 0.5f;
		Vec3 pos = (*camera->GetPosition()) + ((*forward) * d);
		ball->SetPosition(pos);

		//Add the projectile to the collection of rendered gameobjects
		//and the collection of projectiles (which are updated in order
		//to move and collide).
		AddGameObject(ball);

		projectiles.AddGameObject(ball);
		//projectiles.insert(std::make_pair((int)ball, ball));
		//projectiles.push_back(ball);
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
				Fire();
				//exploder->ToggleExploding();
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
		float d = DeltaTime();

		exploder->Update(d);

		//for (pair<int, ProjectileGameObject*> ball : projectiles)
		for(pair<int,GameObject*> ball : *(projectiles.GetDict()))
		{
			((ProjectileGameObject*)ball.second)->Update(d);
		}

		return true;
	}

}