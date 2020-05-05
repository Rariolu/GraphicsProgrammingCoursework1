#include "ExplosionShader.h"

namespace GraphicsProgramming
{

	ExplosionShader::ExplosionShader(string vertFile, string fragFile) : QuadMShader(vertFile, fragFile)
	{
		Init();
	}

	ExplosionShader::ExplosionShader(string geomFile, string vertFile, string fragFile) : QuadMShader(geomFile, vertFile, fragFile)
	{
		Init();
	}

	ExplosionShader::~ExplosionShader()
	{
		QuadMShader::~QuadMShader();
	}

	void ExplosionShader::Init()
	{
		GLuint program = GetProgram();
		timeUniform = glGetUniformLocation(program, "time");
		magUniform = glGetUniformLocation(program, "explosionMagnitude");
		SetFloat(magUniform, magnitude);
	}

	void ExplosionShader::IncreaseTime(float delta)
	{
		if (exploding)
		{
			t += delta;
		}
	}

	void ExplosionShader::SetExploding(bool exp)
	{
		exploding = exp;
		if (!exploding)
		{
			t = defaultT;
		}
	}

	void ExplosionShader::SetExplosionMagnitude(float mag)
	{
		magnitude = mag;
		SetFloat(magUniform, mag);
	}

	void ExplosionShader::ToggleExploding()
	{
		SetExploding(!exploding);
	}

	void ExplosionShader::Update(Transform* transform, Camera* camera)
	{
		float expT = exploding ? t : defaultT;
		SetFloat(timeUniform, expT);
		SetFloat(magUniform, magnitude);
		QuadMShader::Update(transform, camera);
	}

}