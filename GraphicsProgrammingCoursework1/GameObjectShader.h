#ifndef _GAMEOBJECT_SHADER_H
#define _GAMEOBJECT_SHADER_H

#include "Shader.h"
#include "Transform.h"
#include "Camera.h"

namespace GraphicsProgramming
{

	class GameObjectShader : public Shader
	{
		public:
			GameObjectShader(string vertFile, string fragFile);
			GameObjectShader(string geomFile, string vertFile, string fragFile);
			virtual ~GameObjectShader();
			virtual void Update(Transform* transform, Camera* camera) = 0;
	};


}
#endif