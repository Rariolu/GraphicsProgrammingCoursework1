#ifndef _SHADER_H
#define _SHADER_H

#include "glew.h"
#include "Util.h"
#include "Logger.h"

struct ShaderDef
{
	string file;
	unsigned int type;
};

class Shader
{
	public:
		Shader(string geomFile, string vertFile, string fragFile);
		Shader(string vertFile, string fragFile);
		Shader(vector<ShaderDef> shaderDefinitions);

		//Tell openGL to use the executable program associated with this
		//"AbstractShader".
		void Bind();

		void SetFloat(GLuint address, float value);
		void SetVec2(GLuint address, Vec2 value);
		void SetVec3(GLuint address, Vec3 value);
		void SetMatrix(GLuint address, Matrix value);

		void SetFloat(string name, float value);
		void SetVec2(string name, Vec2 value);
		void SetVec3(string name, Vec3 value);
		void SetMatrix(string name, Matrix value);
	protected:
		//Return the address of the executable program.
		GLuint GetProgram();
	private:

		//Attach the openGL shaders to the program
		//on the GPU.
		void AttachShaders();

		//Create an openGL shader from the given text and type
		//before returning its address.
		GLuint CreateShader(string text, unsigned int type);

		//The address of the executable program.
		GLuint program;

		vector<GLuint> shaders;
};

#endif