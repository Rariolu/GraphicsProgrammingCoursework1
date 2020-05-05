#ifndef _QUADMSHADER_H
#define _QUADMSHADER_H

#include "GameObjectShader.h"

namespace GraphicsProgramming
{

	class QuadMShader : public GameObjectShader
	{
	public:
		QuadMShader(string vertFile, string fragFile);
		QuadMShader(string geomFile, string vertFile, string fragFile);
		virtual ~QuadMShader();
		virtual void Update(Transform* transform, Camera* camera);
	private:
		void Init();
		GLuint uniforms[4];
	};

}

#endif