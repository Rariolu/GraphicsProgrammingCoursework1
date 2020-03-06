#ifndef _GAMEOBJECT_SHADER_H
#define _GAMEOBJECT_SHADER_H

#include "Shader.h"
#include "Transform.h"
#include "Camera.h"

class GameObjectShader : public Shader
{
	public:
		GameObjectShader(string vertFile, string fragFile);
		virtual void Update(Transform* transform, Camera* camera)=0;
};

#endif