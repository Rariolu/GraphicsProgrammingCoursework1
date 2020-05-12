#ifndef _MESH_H
#define _MESH_H

#include "glm.hpp"
#include "glew.h"

#include "ObjLoader.h"
#include "Vertex.h"

namespace GraphicsProgramming
{

	//A class which represents a set of vertices, normals,
	//and UV coordinates, which are used to display a 3D model.
	class Mesh
	{
	public:
		~Mesh();

		//Generate a mesh from a set of vertices, normals, and UV coordinates.
		static Mesh* LoadModel(ObjIndexedModel* model);

		//Tell openGL to display the model onscreen.
		void Render();
	private:

		//Create a new instance of "Mesh" (private so that instances can
		//only be made with the "LoadModel" method).
		Mesh();

		//Initialise the mesh based on the given vertices, normals, and UV coordinates.
		void InitialiseModel(ObjIndexedModel* model);

		const static short bufferCount = 4;
		unsigned int drawCount;
		GLuint vertexArrayObject;
		GLuint vertexArrayBuffers[bufferCount];
	};

}

#endif