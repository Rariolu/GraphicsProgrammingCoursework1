#ifndef _FLAKING_OBJECT_H
#define _FLAKING_OBJECT_H

#include "GameObject.h"
#include "PurpleFlakeShader.h"

namespace GraphicsProgramming
{
	class FlakingObject : public GameObject
	{
		public:
			FlakingObject(Mesh* mesh, PurpleFlakeShader* shader, ModelTexture* texture);
			static FlakingObject* GetFlakingObject(string meshName, string shaderName, string textureName);
			void Update(float delta);
		private:
			void Init(PurpleFlakeShader* pfShader);

			PurpleFlakeShader* purpleFlakeShader;
	};
}

#endif