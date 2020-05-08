#include "GraphicsCourseworkScene.h"

namespace GraphicsProgramming
{

	void GraphicsCourseworkScene::Initialise()
	{
		Scene::Initialise();

		camera->SetPosition(0, 0.5f, 0);
		//GameObject* obj = AddGameObject(pyramidMeshName, texture1, tempShader);
		//obj->SetPosition(0, -1, 10);
		//obj->Rotate(AXIS::Y, 180.0f);
	
		ExplodingObject* exploder = ExplodingObject::GetExplodingObject(monkey, explosionShaderName, texture1);

		exploder->SetExplosionMagnitude(2.5f);
		exploder->SetPosition(5, 0.1f, 5);
		//exploder->SetScale(0.0025f);
		AddGameObject(exploder);

		ExplodingObject* exploder2 = ExplodingObject::GetExplodingObject(monkey, explosionShaderName, texture1);
		//exploder2->SetScale(0.0025f);
		exploder2->SetExplosionMagnitude(2.5f);
		exploder2->SetPosition(-10, 0.1f, 1);
		AddGameObject(exploder2);

		exploders.AddGameObject(exploder);
		exploders.AddGameObject(exploder2);

		flaker = FlakingObject::GetFlakingObject(mario, purpleFlakeName, marioTextureName);
		flaker->SetPosition(0, 0, 2.5f);
		flaker->SetScale(0.0025f);
		flaker->Rotate(AXIS::Y, 90);
		AddGameObject(flaker);

		SkyBox* sky = new SkyBox(skyboxFiles, skyboxShaderName);
		SetSkyBox(sky);
	}

	void GraphicsCourseworkScene::DestroyProjectile(ProjectileGameObject* ball)
	{
		projectiles.RemoveGameObject(ball);
		RemoveGameObject(ball);
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

		//exploder->Update(d);

		flaker->Update(d);

		vector<ProjectileGameObject*> destroyedProjectiles;
		
		for (pair<int, GameObject*> expl : *(exploders.GetDict()))
		{
			ExplodingObject* explodingObject = (ExplodingObject*)expl.second;
			explodingObject->Update(d);
		}

		for(pair<int,GameObject*> ball : *(projectiles.GetDict()))
		{
			ProjectileGameObject* proj = (ProjectileGameObject*)ball.second;
			proj->Update(d);
			bool destroyed = false;
			for (pair<int, GameObject*> expl : *(exploders.GetDict()))
			{
				ExplodingObject* explodingObject = (ExplodingObject*)expl.second;
				//explodingObject->Update(d);
				if (explodingObject->CollidesWith(proj))
				{
					destroyed = true;
					destroyedProjectiles.push_back(proj);
					explodingObject->SetExploding(true);
					explodingObject->SetCollider(nullptr);
					break;
				}
			}
			if (!destroyed && !WithinDistance(*proj->GetPosition(), *camera->GetPosition(), 10.0f))
			{
				destroyedProjectiles.push_back(proj);
			}
		}

		for(unsigned int i = 0; i < destroyedProjectiles.size(); i++)
		{
			DestroyProjectile(destroyedProjectiles[i]);
		}

		destroyedProjectiles.clear();

		return true;
	}

}