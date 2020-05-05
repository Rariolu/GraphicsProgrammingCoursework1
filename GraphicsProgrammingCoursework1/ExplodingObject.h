#ifndef _EXPLODING_OBJECT_H
#define _EXPLODING_OBJECT_H

#include "GameObject.h"
#include "ExplosionShader.h"

namespace GraphicsProgramming
{

	class ExplodingObject : public GameObject
	{
		public:
			ExplodingObject(string meshName, string shaderName, string textureName);
			ExplodingObject(Mesh* mesh, ExplosionShader* shader, ModelTexture* texture);
			void SetExploding(bool exp);
			void SetExplosionMagnitude(float mag);
			void ToggleExploding();
			void Update(float delta);
		private:
			void Init(ExplosionShader* shader);
			float magnitude = 10.0f;
			ExplosionShader* explosionShader;
	};
}

#endif