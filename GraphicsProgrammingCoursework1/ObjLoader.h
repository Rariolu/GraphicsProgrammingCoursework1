#ifndef _TEMP_OBJ_LOADER_H
#define _TEMP_OBJ_LOADER_H

#ifndef BLEP

#include <glm.hpp>
#include <vector>
#include <string>

namespace GraphicsProgramming
{

	struct OBJIndex
	{
		unsigned int vertexIndex;
		unsigned int uvIndex;
		unsigned int normalIndex;

		bool operator<(const OBJIndex& r) const { return vertexIndex < r.vertexIndex; }
	};

	class IndexedModel
	{
	public:
		std::vector<glm::vec3> positions;
		std::vector<glm::vec2> texCoords;
		std::vector<glm::vec3> normals;
		std::vector<unsigned int> indices;

		void CalcNormals();
	};

	class OBJModel
	{
	public:
		std::vector<OBJIndex> OBJIndices;
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;
		bool hasUVs;
		bool hasNormals;

		OBJModel(const std::string& fileName);

		IndexedModel ToIndexedModel();
	private:
		unsigned int FindLastVertexIndex(const std::vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const IndexedModel& result);
		void CreateOBJFace(const std::string& line);

		glm::vec2 ParseOBJVec2(const std::string& line);
		glm::vec3 ParseOBJVec3(const std::string& line);
		OBJIndex ParseOBJIndex(const std::string& token, bool* hasUVs, bool* hasNormals);
	};

}

#else

#include <glm.hpp>
#include <vector>
#include <string>
#include "Util.h"
#include "Logger.h"

namespace GraphicsProgramming
{

class ObjIndexedModel
{
public:
	//Calculate the normals based on the position vectors
	//at the vertex indices.
	void CalculateNormals();

	vector<unsigned int> indices;
	vector<Vec3> normals;
	vector<Vec3> positions;
	vector<Vec2> uvCoords;
};

class OBJModel
{
public:
	struct OBJIndex
	{
		bool operator<(const OBJIndex& r) const
		{
			return vertexIndex < r.vertexIndex;
		}
		unsigned int normalIndex;
		unsigned int uvIndex;
		unsigned int vertexIndex;
	};

	OBJModel(const string fileName);
	ObjIndexedModel ToIndexedModel();

	bool hasNormals;
	bool hasUVs;
	vector<OBJIndex> OBJIndices;
	vector<Vec3> normals;
	vector<Vec2> uvs;
	vector<Vec3> vertices;

private:
	void CreateOBJFace(const string line);
	unsigned int FindLastVertexIndex(const vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const ObjIndexedModel& result);
	OBJIndex ParseOBJIndex(const string token, bool* hasUVs, bool* hasNormals);
	Vec2 ParseOBJVec2(const string line);
	Vec3 ParseOBJVec3(const string line);
};

}

#endif

#endif