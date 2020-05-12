#ifndef _TEMP_OBJ_LOADER_H
#define _TEMP_OBJ_LOADER_H

#include <glm.hpp>
#include <vector>
#include <string>
#include "Util.h"
#include "Logger.h"

namespace GraphicsProgramming
{
	//temp
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