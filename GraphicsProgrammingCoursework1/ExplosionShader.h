#ifndef _EXPLOSION_SHADER_H
#define _EXPLOSION_SHADER_H

#include "QuadMShader.h"

namespace GraphicsProgramming
{

	class ExplosionShader : public QuadMShader
	{
		public:
			ExplosionShader(string vertFile, string fragFile);
			ExplosionShader(string geomFile, string vertFile, string fragFile);
			~ExplosionShader();
			void IncreaseTime(float delta);
			void SetExploding(bool exp);
			void SetExplosionMagnitude(float mag);
			void ToggleExploding();
			void Update(Transform* transform, Camera* camera);
		private:
			void Init();
			bool exploding = false;
			const float defaultT = -1.570796327f;
			float t = defaultT;
			float magnitude;
			
			GLuint timeUniform;
			GLuint magUniform;
	};

}

#endif