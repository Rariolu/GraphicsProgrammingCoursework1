#include "Shader.h"

Shader::Shader(string geomFile, string vertFile, string fragFile)
{
	program = glCreateProgram();
	string geomShader = LoadText(geomFile);
	shaders.push_back(CreateShader(geomShader, GL_GEOMETRY_SHADER));
	
	string vertexShader = LoadText(vertFile);
	shaders.push_back(CreateShader(vertexShader, GL_VERTEX_SHADER));
	
	string fragShader = LoadText(fragFile);
	CreateShader(fragShader, GL_FRAGMENT_SHADER);

	AttachShaders();
}

Shader::Shader(string vertFile, string fragFile)
{
	program = glCreateProgram();

	string vertexShader = LoadText(vertFile);
	shaders.push_back(CreateShader(vertexShader, GL_VERTEX_SHADER));

	string fragShader = LoadText(fragFile);
	CreateShader(fragShader, GL_FRAGMENT_SHADER);

	AttachShaders();
}

void Shader::Bind()
{
	glUseProgram(program);
}

void Shader::SetFloat(string name, float value)
{
	glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::SetVec2(string name, Vec2 value)
{
	glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(string name, Vec3 value)
{
	glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}

void Shader::SetMatrix(string name, Matrix value)
{
	glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

GLuint Shader::GetProgram()
{
	return program;
}

void Shader::AttachShaders()
{
	for (int i = 0; i < shaders.size(); i++)
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