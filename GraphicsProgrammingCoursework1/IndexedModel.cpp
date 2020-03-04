#include "IndexedModel.h"

void IndexedModel::CalculateNormals()
{
	for (unsigned int i = 0; i < indices.size(); i += 3)
	{
		int a = indices[i];
		int b = indices[i + 1];
		int c = indices[i + 2];

		Vec3 v1 = positions[b] - positions[a];
		Vec3 v2 = positions[c] - positions[a];

		Vec3 normal = glm::normalize(glm::cross(v1, v2));
		normals[a] += normal;
		normals[b] += normal;
		normals[c] += normal;
	}
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		normals[i] = glm::normalize(normals[i]);
	}
}