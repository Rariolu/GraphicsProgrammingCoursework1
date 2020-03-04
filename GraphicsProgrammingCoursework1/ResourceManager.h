#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include "Mesh.h"
#include "ModelTexture.h"
#include "Shader.h"

//Forward declaration of "Scene" because the Scene class
//uses the ResourceManager so referencing the Scene header
//here would cause a recursive declaration.
class Scene;

class ResourceManager
{
public:
	~ResourceManager();
	static ResourceManager* Instance();
	void AddMesh(string name, Mesh* Mesh);
	void AddModelTexture(string name, ModelTexture* modelTexture);
	void AddScene(string name, Scene* Scene);
	void AddShader(string name, Shader* shader);
	Mesh* GetMesh(string name);
	ModelTexture* GetModelTexture(string name);
	Scene* GetScene(string name);
	Shader* GetShader(string name);
private:
	ResourceManager();
	static ResourceManager* instance;
	strmap<Mesh*> meshes;
	strmap<ModelTexture*> modelTextures;
	strmap<Scene*> scenes;
	strmap<Shader*> shaders;
};

#endif