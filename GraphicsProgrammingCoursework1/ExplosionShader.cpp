#include "ExplosionShader.h"

ExplosionShader::ExplosionShader(string vertFile, string fragFile) : QuadMShader(vertFile,fragFile)
{
	Init();
}

ExplosionShader::ExplosionShader(string geomFile, string vertFile, string fragFile) : QuadMShader(geomFile, vertFile, fragFile)
{
	Init();
}

void ExplosionShader::Init()
{
	GLuint program = GetProgram();
	timeUniform = glGetUniformLocation(program, "time");
}

void ExplosionShader::IncreaseTime(float delta)
{
	t += delta;
}

void ExplosionShader::SetExploding(bool exp)
{
	exploding = exp;
	if (!exploding)
	{
		t = 0;
	}
}

void ExplosionShader::Update(Transform* transform, Camera* camera)
{
	QuadMShader::Update(transform, camera);
	SetFloat(timeUniform, exploding ? t : 0);
}