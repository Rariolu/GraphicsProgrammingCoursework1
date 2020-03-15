#include "Scene.h"

Scene::Scene()
{
	audioDevice = AudioDevice::Instance();
	sdlWindowManager = SDLWindowManager::Instance();
	camera = new Camera(70.0f, sdlWindowManager->GetScreenWidth() / sdlWindowManager->GetScreenHeight(), 0.01f, 1000.0f);
	resourceManager = ResourceManager::Instance();
}

Scene::~Scene()
{
	//Delete pointers in order to free up
	//memory.
	delete audioDevice;
	delete camera;
	Dispose();
}

void Scene::Dispose()
{
	initialised = false;
	//Delete all the gameobjects from memory 
	//to free up resources.
	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
	gameObjects.clear();
	nextScene = "";
}

void Scene::Initialise()
{
	initialised = true;
	audioDevice->SetListener(camera);
}

string Scene::Run()
{
	//Only run game loop if the scene
	//has been initialised.
	if (initialised)
	{
		bool loop = true;
		//While another scene hasn't been
		//requested and the user's input
		//and gameplay don't request the
		//scene to end.
		while (loop && nextScene == "")
		{
			//Update the value of "deltaTime" to represent
			//the amount of time since the last frame.
			GenerateDeltaTime();

			//Process key and mouse events.
			bool input = GetInput();

			//Process game logic.
			bool update = Update();

			//Render the gameobjects and skybox.
			Render();
			loop = input && update;
		}
	}
	return nextScene;
}

GameObject* Scene::AddGameObject(string meshName, string textureName, string shaderName)
{
	//Get the mesh, texture, and shader from the resource manager using the given names.
	return AddGameObject(resourceManager->GetMesh(meshName), resourceManager->GetModelTexture(textureName), (GameObjectShader*)resourceManager->GetShader(shaderName));
}

GameObject* Scene::AddGameObject(Mesh* mesh, ModelTexture* texture, GameObjectShader* shader)
{
	//Create a new gameobject using the given mesh, shader, and texture.
	GameObject* gameObject = new GameObject(mesh, shader, texture);

	//Add the gameobject to the collection of gameobjects to be rendered.
	AddGameObject(gameObject);

	//Return the gameobject pointer so it can be used elsewhere.
	return gameObject;
}

void Scene::AddGameObject(GameObject* gameObject)
{
	//Set the camera that's viewing the gameobject
	//to be the one from this scene so it is rendered
	//according to the position and orientation of that
	//camera.
	gameObject->SetCamera(camera);
	gameObjects.push_back(gameObject);
}

float Scene::DeltaTime()
{
	return deltaTime;
}

void Scene::GenerateDeltaTime()
{
	//Determine the current time stamp and subtract
	//the previous time stamp to determine
	//the amount of time that occurred between frames.
	float currentTime = (float)SDL_GetTicks() / 1000.0f;
	float milliseconds = (currentTime - previousTimeStamp);
	previousTimeStamp = currentTime;
	deltaTime = milliseconds;
}

void Scene::RemoveGameObject(GameObject* gameObject)
{
	//Iterate through the collection of gameobjects to find
	//the one that's requested, then erase it from the collection.
	if (gameObjects.size() > 0)
	{
		for (vector<GameObject*>::iterator i = gameObjects.begin(); i < gameObjects.end(); i++)
		{
			if (gameObject == (*i))
			{
				gameObjects.erase(i);
				break;
			}
		}
	}
}

void Scene::SetNextScene(string scenename)
{
	nextScene = scenename;
}

bool Scene::GetInput()
{
	//Iterate through all SDL events and process them.
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			return false;
		}
		case SDL_KEYDOWN:
		{
			SDL_Keycode keycode = event.key.keysym.sym;
			if (!KeyDown(keycode))
			{
				return false;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			SDL_MouseButtonEvent mousebutton = event.button;
			if (!MouseDown(mousebutton))
			{
				return false;
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return true;
}

void Scene::Render()
{
	//Clear the display so that it only shows the specified
	//RGBA values.
	sdlWindowManager->ClearDisplay(1.0f, 0.5f, 1.0f, 1.0f);

	//Iterate through the gameobjects and render them.
	for (GameObject* go : gameObjects)
	{
		go->Render();
	}

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	//Swap the window buffers
	sdlWindowManager->SwapBuffer();
}