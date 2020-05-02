#include "Shader.h"

Shader::Shader(string geomFile, string vertFile, string fragFile)
	: Shader(new ShaderDef[3]{{geomFile,GL_GEOMETRY_SHADER},{vertFile,GL_VERTEX_SHADER},{fragFile,GL_FRAGMENT_SHADER}},3)
{

}

Shader::Shader(string vertFile, string fragFile) :
Shader(new ShaderDef[2]{{vertFile,GL_VERTEX_SHADER},{fragFile,GL_FRAGMENT_SHADER} },2)
{
	
}

Shader::Shader(ShaderDef* shaderDefinitions, unsigned int length)
{
	program = glCreateProgram();

	for(unsigned int i = 0; i < length; i++)
	{
		ShaderDef shaderDef = shaderDefinitions[i];
		string shaderText = LoadText(shaderDef.file);
		shaders.push_back(CreateShader(shaderText, shaderDef.type));
	}

	AttachShaders();

	glLinkProgram(program);
	glValidateProgram(program);
}

void Shader::Bind()
{
	glUseProgram(program);
}

void Shader::SetFloat(GLuint address, float value)
{
	glUniform1f(address, value);
}

void Shader::SetFloat(string name, float value)
{
	SetFloat(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::SetInt(GLuint address, int value)
{
	glUniform1i(address, value);
}

void Shader::SetInt(string name, int value)
{
	SetInt(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::SetMatrix(GLuint address, Matrix value)
{
	glUniformMatrix4fv(address, 1, GL_FALSE, &value[0][0]);
}

void Shader::SetMatrix(string name, Matrix value)
{
	SetMatrix(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::SetVec2(GLuint address, Vec2 value)
{
	glUniform2fv(address, 1, &value[0]);
}

void Shader::SetVec2(string name, Vec2 value)
{
	SetVec2(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::SetVec3(GLuint address, Vec3 value)
{
	glUniform3fv(address, 1, &value[0]);
}

void Shader::SetVec3(string name, Vec3 value)
{
	SetVec3(glGetUniformLocation(program, name.c_str()), value);
}

GLuint Shader::GetProgram()
{
	return program;
}

void Shader::AttachShaders()
{
	for (unsigned int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(program, shaders[i]);
	}
}

GLuint Shader::CreateShader(string text, unsigned int type)
{
	GLuint shader = glCreateShader(type);

	if (!shader)
	{
		Log("Shader failed to be created.");
	}

	const GLchar* stringsource[] = { text.c_str() };
	GLint lengths[] = { text.length() };

	glShaderSource(shader, 1, stringsource, lengths);
	glCompileShader(shader);

	return shader;
}