#ifndef _PURPLE_FLAKE_SHADER_H
#define _PURPLE_FLAKE_SHADER_H

#include "QuadMShader.h"

namespace GraphicsProgramming
{
	class PurpleFlakeShader : public QuadMShader
	{
		public:
			PurpleFlakeShader(string geomFile, string vertFile, string fragFile);
			PurpleFlakeShader(PurpleFlakeShader& pfShader);
			void IncreaseTime(float delta);
			void Update(Transform* transform, Camera* camera);
		private:
			void Init();

			const float acceleration = -1.0f;
			Vec3 force = Vec3(0.01f, acceleration, -0.07f);
			float time = 0;

			GLuint timeUniform;
			GLuint forceUniform;
	};
}

#endif