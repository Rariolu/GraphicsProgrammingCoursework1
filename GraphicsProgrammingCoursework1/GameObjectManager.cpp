#include "GameObjectManager.h"

namespace GraphicsProgramming
{
	GameObjectManager::GameObjectManager()
	{

	}

	GameObjectManager::~GameObjectManager()
	{
		for (pair<int, GameObject*> gameObject : gameObjects)
		{
			delete gameObject.second;
		}
		gameObjects.clear();
	}

	void GameObjectManager::AddGameObject(GameObject* gameObject)
	{
		map<int, GameObject*>::iterator iter = gameObjects.find((int)gameObject);
		if (iter == gameObjects.end())
		{
			gameObjects.insert(std::make_pair((int)gameObject, gameObject));
		}
	}

	void GameObjectManager::Clear()
	{
		gameObjects.clear();
	}

	void GameObjectManager::RemoveGameObject(GameObject* gameObject)
	{
		map<int, GameObject*>::iterator iter = gameObjects.find((int)gameObject);
		if (iter != gameObjects.end())
		{
			//delete iter->second;
			iter = gameObjects.erase(iter);
		}
	}

	map<int, GameObject*>* GameObjectManager::GetDict()
	{
		return &gameObjects;
	}
}