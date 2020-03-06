#ifndef _QUADMSHADER_H
#define _QUADMSHADER_H

#include "GameObjectShader.h"

class QuadMShader : public GameObjectShader
{
	public:
		QuadMShader(string vertFile, string fragFile);
		void Update(Transform* transform, Camera* camera);
	private:
		GLuint uniforms[4];
};

#endif