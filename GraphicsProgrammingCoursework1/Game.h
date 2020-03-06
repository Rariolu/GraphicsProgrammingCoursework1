#ifndef _GAME_H
#define _GAME_H

#include "Scene.h"
#include "SDLWindowManager.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "ObjLoader.h"
#include "ModelTexture.h"
#include "QuadMShader.h"

//A class which manages the entire
//program.
class Game
{
public:
	static Game* Instance();

	~Game();

	//Attempt to create a window, load external resources into memory,
	//and execute the default first scene.
	int CreateWindow(string windowTitle, float width, float height);

	//Dispose of allocated resources.
	void Dispose();

private:
	Game();

	//Load external resources (e.g. textures, models, etc.) into memory
	void ResourceSetup();

	//Load a mesh from a given file path and then
	//add it into the resource manager using the given name.
	void SetupMesh(string name, string objfile);

	//Run the scene associated with the given name.
	void Run(string startScene);

	//A pointer to the resource manager.
	ResourceManager* resourceManager;

	//A pointer to the SDL window manager.
	SDLWindowManager* windowManager;

	//The current instance of this class.
	static Game* instance;
};

#endif