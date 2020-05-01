#ifndef _EXPLOSION_SHADER_H
#define _EXPLOSION_SHADER_H

#include "QuadMShader.h"

class ExplosionShader :	public QuadMShader
{
	public:
		ExplosionShader(string vertFile, string fragFile);
		ExplosionShader(string geomFile, string vertFile, string fragFile);
		void SetExploding(bool exp);
		void Update(Transform* transform, Camera* camera);
	
	private:
		bool exploding = false;
};

#endif