#include "Mesh.h"

namespace GraphicsProgramming
{

	Mesh::Mesh()
	{
		drawCount = vertexArrayObject = 0;
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &vertexArrayObject);
	}

	void Mesh::Render()
	{
		glBindVertexArray(vertexArrayObject);
		glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, drawCount);
		glBindVertexArray(0);
	}

	Mesh* Mesh::LoadModel(ObjIndexedModel* model)
	{
		Mesh* mesh = new Mesh();
		mesh->InitialiseModel(model);
		return mesh;
	}

	void Mesh::InitialiseModel(ObjIndexedModel* model)
	{
		drawCount = model->indices.size();

		glGenVertexArrays(1, &vertexArrayObject); //generate a vertex array and store it in the VAO
		glBindVertexArray(vertexArrayObject); //bind the VAO (any operation that works on a VAO will work on our bound VAO - binding)

		glGenBuffers(4, vertexArrayBuffers); //generate our buffers based of our array of data/buffers - GLuint vertexArrayBuffers[NUM_BUFFERS];

		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[0]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
		glBufferData(GL_ARRAY_BUFFER, model->positions.size() * sizeof(model->positions[0]), &model->positions[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU (determined by type)
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[1]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
		glBufferData(GL_ARRAY_BUFFER, model->positions.size() * sizeof(model->uvCoords[0]), &model->uvCoords[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(model->normals[0]) * model->normals.size(), &model->normals[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[3]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, model->indices.size() * sizeof(model->indices[0]), &model->indices[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU

		glBindVertexArray(0); // unbind our VAO
	}

}