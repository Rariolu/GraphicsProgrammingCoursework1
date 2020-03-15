#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	resourceManager = ResourceManager::Instance();
	windowManager = nullptr;
}

Game::~Game()
{
	Dispose();
}

Game* Game::Instance()
{
	if (!instance)
	{
		return instance = new Game();
	}
	return instance;
}

int Game::CreateWindow(string windowTitle, float width, float height)
{
	bool initialised = SDLWindowManager::GenerateWindowManager(windowTitle, width, height, windowManager);
	if (!initialised)
	{
		return -1;
	}
	ResourceSetup();
	Run(sceneName);
	return 0;
}

void Game::Dispose()
{
	delete resourceManager;
	delete windowManager;
}

void Game::ResourceSetup()
{
	//Models

	//SetupMesh("mon", "..\\Resources\\monkey3.obj");
	SetupMesh(mario, marioFile);

	//Textures

	ModelTexture* texture = new ModelTexture(texture1File);
	resourceManager->AddModelTexture(texture1, texture);

	//Scenes

	resourceManager->AddScene(sceneName, new GraphicsCourseworkScene());
}

void Game::SetupMesh(string name, string objfile)
{
	OBJModel model(objfile);
	ObjIndexedModel imodel = model.ToIndexedModel();
	Mesh* mesh = Mesh::LoadModel(&imodel);
	if (mesh)
	{
		resourceManager->AddMesh(name, mesh);
	}
}

void Game::Run(string startScene)
{
	string nextScene = startScene;
	Scene* currentScene;
	while (currentScene = resourceManager->GetScene(nextScene))
	{
		currentScene->Initialise();
		nextScene = currentScene->Run();
		currentScene->Dispose();
	}
}