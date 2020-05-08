#ifndef _EXPLODING_OBJECT_H
#define _EXPLODING_OBJECT_H

#include "GameObject.h"
#include "ExplosionShader.h"
#include "SphereCollider.h"

namespace GraphicsProgramming
{
	class ExplodingObject : public GameObject
	{
		public:
			//ExplodingObject(string meshName, string shaderName, string textureName);
			ExplodingObject(Mesh* mesh, ExplosionShader* shader, ModelTexture* texture);
			static ExplodingObject* GetExplodingObject(string meshName, string shaderName, string textureName);
			void SetExploding(bool exp);
			void SetExplosionMagnitude(float mag);
			void ToggleExploding();
			void Update(float delta);
		private:
			void Init(ExplosionShader* shader);
			float magnitude = 10.0f;
			bool exploding = false;
			ExplosionShader* explosionShader;
	};
}

#endif