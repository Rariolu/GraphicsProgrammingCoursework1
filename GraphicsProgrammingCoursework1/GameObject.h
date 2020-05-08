#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "GameObjectShader.h"
#include "ResourceManager.h"
#include "Collider.h"

namespace GraphicsProgramming
{

	class GameObject : public Transform
	{
	public:
		GameObject(string meshName, string shaderName, string textureName);
		GameObject(Mesh* mesh, GameObjectShader* shader, ModelTexture* texture);
		~GameObject();

		//Detects a collision between two GameObjects
		//using their colliders.
		bool CollidesWith(GameObject* other);

		//Get the collider that's attached to this gameobject.
		Collider* GetCollider();

		//Returns true if this GameObject is "active"
		//(meaning it is visible and can be collided with).
		bool IsActive();

		//Bind the relevant mesh, shader, and texture
		//in order to render this model to the screen.
		void Render();

		//Set the active state of this gameobject
		//(when it's active, it is rendered and
		//can be collided with).
		void SetActive(bool active);

		//Set the camera that's used to render this gameobject.
		void SetCamera(Camera* cam);

		//Set the collider that's used to determine
		//collisions with other gameobjects.
		void SetCollider(Collider* col);

	protected:
		//A pointer to the "ResourceManager" so that
		//resources can be loaded (e.g. shaders, textures, etc.).
		static ResourceManager* rescManager;
	private:

		void Init(Mesh* mesh, GameObjectShader* shader, ModelTexture* texture);

		//The camera that's used to render this gameobject.
		Camera* camera;

		//The collider that's used to determine
		//collisions with other gameobjects.
		Collider* collider;

		//The active state of this gameobject.
		bool isActive = true;

		//The mesh (collection of vertices) to determine
		//the gameobject's shape.
		Mesh* mesh;



		//The shader that's used to render the mesh.
		GameObjectShader* shader;

		//The texture that's applied to the mesh in order
		//to specify its appearance.
		ModelTexture* texture;
	};

}

#endif