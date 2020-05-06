#ifndef _GAMEOBJECT_MANAGER_H
#define _GAMEOBJECT_MANAGER_H

#include "GameObject.h"

namespace GraphicsProgramming
{

	class GameObjectManager
	{
		public:
			GameObjectManager();
			~GameObjectManager();
			void AddGameObject(GameObject* gameObject);
			void RemoveGameObject(GameObject* gameObject);
			map<int, GameObject*>* GetDict();
		private:
			map<int, GameObject*> gameObjects;
	};

}

#endif