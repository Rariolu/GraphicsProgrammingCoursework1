#include "QuadMShader.h"

namespace GraphicsProgramming
{

	QuadMShader::QuadMShader(string vertFile, string fragFile) : GameObjectShader(vertFile, fragFile)
	{
		Init();
	}

	QuadMShader::QuadMShader(string geomFile, string vertFile, string fragFile) : GameObjectShader(geomFile, vertFile, fragFile)
	{
		Init();
	}

	QuadMShader::QuadMShader(QuadMShader& qmShader)
		: GameObjectShader(qmShader)
	{
		Init();
	}

	QuadMShader::~QuadMShader()
	{
		GameObjectShader::~GameObjectShader();
	}

	void QuadMShader::Init()
	{
		GLuint program = GetProgram();

		glBindAttribLocation(program, 0, "position");
		glBindAttribLocation(program, 1, "texCoord");

		uniforms[0] = glGetUniformLocation(program, "positionMatrix");
		uniforms[1] = glGetUniformLocation(program, "rotationMatrix");
		uniforms[2] = glGetUniformLocation(program, "scaleMatrix");
		uniforms[3] = glGetUniformLocation(program, "viewProjection");
	}

	void QuadMShader::Update(Transform* transform, Camera* camera)
	{
		Matrix positionMatrix = glm::translate(*transform->GetPosition());
		Vec3 r = *transform->GetRotation();
		Matrix rotX = glm::rotate(r.x, Vec3(1, 0, 0));
		Matrix rotY = glm::rotate(r.y, Vec3(0, 1, 0));
		Matrix rotZ = glm::rotate(r.z, Vec3(0, 0, 1));
		Matrix rotationMatrix = rotX * rotY * rotZ;
		Matrix scaleMatrix = glm::scale(*transform->GetScale());
		SetMatrix(uniforms[0], positionMatrix);
		SetMatrix(uniforms[1], rotationMatrix);
		SetMatrix(uniforms[2], scaleMatrix);
		SetMatrix(uniforms[3], camera->GetViewProjection());
	}

}