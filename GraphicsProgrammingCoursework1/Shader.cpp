#include "Shader.h"

namespace GraphicsProgramming
{

	Shader::Shader(string geomFile, string vertFile, string fragFile)
		: Shader(new ShaderDef[3]{ {geomFile,GL_GEOMETRY_SHADER},{vertFile,GL_VERTEX_SHADER},{fragFile,GL_FRAGMENT_SHADER} }, 3)
	{

	}

	Shader::Shader(string vertFile, string fragFile) :
		Shader(new ShaderDef[2]{ {vertFile,GL_VERTEX_SHADER},{fragFile,GL_FRAGMENT_SHADER} }, 2)
	{

	}

	Shader::Shader(ShaderDef* shaderDefs, unsigned int length)
	{
		Init(shaderDefs, length);
	}

	Shader::Shader(Shader& shader)
	{
		unsigned int length = shader.GetL();
		ShaderDef* shaderDefs = shader.GetShaderDefinitions();
		Init(shaderDefs, length);
	}

	Shader::~Shader()
	{
		for (unsigned int i = 0; i < shaders.size(); i++)
		{
			glDetachShader(program, shaders[i]);
			glDeleteShader(shaders[i]);
		}
		glDeleteProgram(program);
	}

	void Shader::Bind()
	{
		glUseProgram(program);
	}

	ShaderDef* Shader::GetShaderDefinitions()
	{
		return shaderDefinitions;
	}

	unsigned int Shader::GetL()
	{
		return l;
	}

	void Shader::SetFloat(GLuint address, float value)
	{
		glUniform1f(address, value);
	}

	void Shader::SetFloat(string name, float value)
	{
		SetFloat(GetUniformAddress(name), value);
	}

	void Shader::SetInt(GLuint address, int value)
	{
		glUniform1i(address, value);
	}

	void Shader::SetInt(string name, int value)
	{
		SetInt(GetUniformAddress(name), value);
	}

	void Shader::SetMatrix(GLuint address, Matrix value)
	{
		glUniformMatrix4fv(address, 1, GL_FALSE, &value[0][0]);
	}

	void Shader::SetMatrix(string name, Matrix value)
	{
		SetMatrix(GetUniformAddress(name), value);
	}

	void Shader::SetVec2(GLuint address, Vec2 value)
	{
		glUniform2fv(address, 1, &value[0]);
	}

	void Shader::SetVec2(string name, Vec2 value)
	{
		SetVec2(GetUniformAddress(name), value);
	}

	void Shader::SetVec3(GLuint address, Vec3 value)
	{
		glUniform3fv(address, 1, &value[0]);
	}

	void Shader::SetVec3(string name, Vec3 value)
	{
		SetVec3(GetUniformAddress(name), value);
	}

	GLuint Shader::GetProgram()
	{
		return program;
	}

	GLuint Shader::GetUniformAddress(string name)
	{
		GLuint address = glGetUniformLocation(program, name.c_str());
		if (address == -1)
		{
			Log("\"" + name + "\" link failed.");
		}
		return address;
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

	void Shader::Init(ShaderDef* shaderDefs, unsigned int length)
	{
		program = glCreateProgram();

		shaderDefinitions = shaderDefs;
		l = length;
		for (unsigned int i = 0; i < length; i++)
		{
			ShaderDef shaderDef = shaderDefinitions[i];
			string* shaderText = LoadText(shaderDef.file);
			string text = "";
			if (shaderText)
			{
				text = *shaderText;
				delete shaderText;
			}
			/*else
			{
				Log(shaderDef.file+" failed to load.");
				map<unsigned int, string>::iterator iter = quadMShaders.find(shaderDef.type);
				if (iter != quadMShaders.end())
				{
					text = iter->second;
				}
			}*/
			shaders.push_back(CreateShader(text, shaderDef.type));
		}

		AttachShaders();

		glLinkProgram(program);
		glValidateProgram(program);
	}
}