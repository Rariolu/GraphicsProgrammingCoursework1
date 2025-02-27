#include "Game.h"

namespace GraphicsProgramming
{

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

	int Game::CreateWindow(string windowTitle, float width, float height, Icon icon)
	{
		bool initialised = SDLWindowManager::GenerateWindowManager(windowTitle, width, height, windowManager);
		if (!initialised)
		{
			return -1;
		}
		SDLWindowManager::Instance()->SetSDLIcon(icon);
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

		SetupMesh(mario, marioFile);

		SetupMesh(monkey, monkeyFile);

		SetupMesh(ballMeshName, ballMeshFile);

		//Textures

		ModelTexture* texture = new ModelTexture(texture1File);
		resourceManager->AddModelTexture(texture1, texture);

		ModelTexture* marioTexture = new ModelTexture(marioTextureFile);
		resourceManager->AddModelTexture(marioTextureName, marioTexture);

		ModelTexture* t2 = new ModelTexture(texture2File);
		resourceManager->AddModelTexture(texture2, t2);

		//Shaders

		QuadMShader* shader = new QuadMShader(tempShaderVertFile, tempShaderFragFile);
		resourceManager->AddShader(tempShader, shader);

		ExplosionShader* explosionShader = new ExplosionShader(explosionShaderGeomFile, explosionShaderVertFile, explosionShaderFragFile);
		resourceManager->AddShader(explosionShaderName, explosionShader);

		PurpleFlakeShader* purpleFlakeShader = new PurpleFlakeShader(purpleFlakeGeomFile, purpleFlakeVertFile, purpleFlakeFragFile);
		resourceManager->AddShader(purpleFlakeName, purpleFlakeShader);

		SkyBoxShader* skyboxShader = new SkyBoxShader(skyboxShaderVertFile, skyboxShaderFragFile);
		resourceManager->AddShader(skyboxShaderName, skyboxShader);

		Shader* textShader = new Shader(textShaderVertFile, textShaderFragFile);
		
		//Fonts

		Font* arial = Font::GetFont(fontFile);
		arial->SetShader(textShader);
		arial->SetDimensions(windowWidth, windowHeight);
		resourceManager->AddFont(fontName, arial);

		//Scenes

		resourceManager->AddScene(sceneName, new GraphicsCourseworkScene());
	}

	void Game::SetupMesh(string name, string objfile)
	{
		OBJModel model(objfile);
		ObjIndexedModel imodel = model.ToIndexedModel();
		//IndexedModel imodel = model.ToIndexedModel();
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

}