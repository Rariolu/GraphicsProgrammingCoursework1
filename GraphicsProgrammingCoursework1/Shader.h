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
		Shader(ShaderDef* shaderDefinitions, unsigned int length);

		//Tell openGL to use the executable program associated with this
		//"AbstractShader".
		void Bind();

		//Set the value of the float uniform
		//at the given address.
		void SetFloat(GLuint address, float value);
		void SetFloat(string name, float value);

		void SetInt(GLuint address, int value);
		void SetInt(string name, int value);

		//Set the value of the mat4 uniform
		//at the given address.
		void SetMatrix(GLuint address, Matrix value);
		void SetMatrix(string name, Matrix value);

		//Set the value of the vec2 uniform
		//at the given address.
		void SetVec2(GLuint address, Vec2 value);
		void SetVec2(string name, Vec2 value);

		//Set the value of the vec3 uniform
		//at the given address.
		void SetVec3(GLuint address, Vec3 value);
		void SetVec3(string name, Vec3 value);

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