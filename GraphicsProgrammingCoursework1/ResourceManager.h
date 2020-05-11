#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include "Mesh.h"
#include "ModelTexture.h"
#include "Font.h"

namespace GraphicsProgramming
{

	//Forward declaration of "Scene" because the Scene class
	//uses the ResourceManager so referencing the Scene header
	//here would cause a recursive declaration.
	class Scene;

	class ResourceManager
	{
	public:
		~ResourceManager();
		static ResourceManager* Instance();
		void AddFont(string name, Font* font);
		void AddMesh(string name, Mesh* Mesh);
		void AddModelTexture(string name, ModelTexture* modelTexture);
		void AddScene(string name, Scene* Scene);
		void AddShader(string name, Shader* shader);
		Font* GetFont(string name);
		Mesh* GetMesh(string name);
		ModelTexture* GetModelTexture(string name);
		Scene* GetScene(string name);
		Shader* GetShader(string name);
	private:
		ResourceManager();
		static ResourceManager* instance;
		strmap<Font*> fonts;
		strmap<Mesh*> meshes;
		strmap<ModelTexture*> modelTextures;
		strmap<Scene*> scenes;
		strmap<Shader*> shaders;
	};

}

#endif