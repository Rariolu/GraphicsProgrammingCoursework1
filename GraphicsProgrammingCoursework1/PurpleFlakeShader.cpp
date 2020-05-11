#include "PurpleFlakeShader.h"

namespace GraphicsProgramming
{
	PurpleFlakeShader::PurpleFlakeShader(string geomFile, string vertFile, string fragFile)
		: QuadMShader(geomFile,vertFile,fragFile)
	{
		Init();
	}

	PurpleFlakeShader::PurpleFlakeShader(PurpleFlakeShader& pfShader)
		: QuadMShader(pfShader)
	{
		Init();
	}

	void PurpleFlakeShader::IncreaseTime(float delta)
	{
		time += delta;
	}

	void PurpleFlakeShader::Update(Transform* transform, Camera* camera)
	{
		SetVec3(forceUniform, force);
		SetFloat(timeUniform, time);
		QuadMShader::Update(transform, camera);
	}

	void PurpleFlakeShader::Init()
	{
		GLuint program = GetProgram();
		timeUniform = GetUniformAddress("time");
		forceUniform = GetUniformAddress("force");
	}
}