#include "ExplosionShader.h"

ExplosionShader::ExplosionShader(string vertFile, string fragFile) : QuadMShader(vertFile,fragFile)
{

}

ExplosionShader::ExplosionShader(string geomFile, string vertFile, string fragFile) : QuadMShader(geomFile, vertFile, fragFile)
{

}

void ExplosionShader::SetExploding(bool exp)
{
	exploding = exp;
}

void ExplosionShader::Update(Transform* transform, Camera* camera)
{
	QuadMShader::Update(transform, camera);
}