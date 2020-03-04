#include "Mesh.h"

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
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
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

	//Generate and bind vertex array.
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	unsigned int positionsSize = model->positions.size() * sizeof(model->positions[0]);
	unsigned int uvSize = model->uvCoords.size() * sizeof(model->uvCoords[0]);
	unsigned int normalSize = model->normals.size() * sizeof(model->normals[0]);
	unsigned int indexSize = model->indices.size() * sizeof(model->indices[0]);

	//Generate buffers
	glGenBuffers(bufferCount, vertexArrayBuffers);

	//Bind and populate Position buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[0]);
	glBufferData(GL_ARRAY_BUFFER, positionsSize, &model->positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Bind and populate UV buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[1]);
	//glBufferData(GL_ARRAY_BUFFER, uvSize, &model->uvCoordinates[1], GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, uvSize, &model->uvCoords[1], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//Bind and populate Normal buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[2]);
	glBufferData(GL_ARRAY_BUFFER, normalSize, &model->normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//Bind and populate Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, &model->indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}