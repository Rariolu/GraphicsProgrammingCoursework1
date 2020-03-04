#include "ObjLoader.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

bool CompareOBJIndexPtr(const OBJModel::OBJIndex* a, const OBJModel::OBJIndex* b);
inline unsigned int ParseOBJIndexValue(const string& token, unsigned int start, unsigned int end);
inline float ParseOBJFloatValue(const string& token, unsigned int start, unsigned int end);

void ObjIndexedModel::CalculateNormals()
{
	for (unsigned int i = 0; i < indices.size(); i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + 1];
		int i2 = indices[i + 2];

		Vec3 v1 = positions[i1] - positions[i0];
		Vec3 v2 = positions[i2] - positions[i0];

		Vec3 normal = glm::normalize(glm::cross(v1, v2));

		normals[i0] += normal;
		normals[i1] += normal;
		normals[i2] += normal;
	}

	for (unsigned int i = 0; i < positions.size(); i++)
	{
		normals[i] = glm::normalize(normals[i]);
	}
}

OBJModel::OBJModel(const string fileName)
{
	hasUVs = false;
	hasNormals = false;
	InputFileStream file;
	file.open(fileName.c_str());

	string line;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);

			unsigned int lineLength = line.length();

			if (lineLength < 2)
				continue;

			const char* lineCStr = line.c_str();

			switch (lineCStr[0])
			{
			case 'v':
			{
				if (lineCStr[1] == 't')
				{
					this->uvs.push_back(ParseOBJVec2(line));
				}
				else if (lineCStr[1] == 'n')
				{
					this->normals.push_back(ParseOBJVec3(line));
				}
				else if (lineCStr[1] == ' ' || lineCStr[1] == '\t')
				{
					this->vertices.push_back(ParseOBJVec3(line));
				}
				break;
			}
			case 'f':
			{
				CreateOBJFace(line);
				break;
			}
			default: break;
			};
		}
	}
	else
	{
		Log("Unable to load mesh: \"" + fileName + "\".");
	}
}



ObjIndexedModel OBJModel::ToIndexedModel()
{
	ObjIndexedModel result;
	ObjIndexedModel normalModel;

	unsigned int numIndices = OBJIndices.size();

	vector<OBJIndex*> indexLookup;

	for (unsigned int i = 0; i < numIndices; i++)
	{
		indexLookup.push_back(&OBJIndices[i]);
	}

	std::sort(indexLookup.begin(), indexLookup.end(), CompareOBJIndexPtr);

	map<OBJIndex, unsigned int> normalModelIndexMap;
	map<unsigned int, unsigned int> indexMap;

	for (unsigned int i = 0; i < numIndices; i++)
	{
		OBJIndex* currentIndex = &OBJIndices[i];

		Vec3 currentPosition = vertices[currentIndex->vertexIndex];
		Vec2 currentTexCoord;
		Vec3 currentNormal;

		if (hasUVs)
		{
			currentTexCoord = uvs[currentIndex->uvIndex];
		}
		else
		{
			currentTexCoord = Vec2(0, 0);
		}
		if (hasNormals)
		{
			currentNormal = normals[currentIndex->normalIndex];
		}
		else
		{
			currentNormal = Vec3(0, 0, 0);
		}
		unsigned int normalModelIndex;
		unsigned int resultModelIndex;

		//Create model to properly generate normals on
		map<OBJIndex, unsigned int>::iterator it = normalModelIndexMap.find(*currentIndex);
		if (it == normalModelIndexMap.end())
		{
			normalModelIndex = normalModel.positions.size();

			normalModelIndexMap.insert(pair<OBJIndex, unsigned int>(*currentIndex, normalModelIndex));
			normalModel.positions.push_back(currentPosition);
			normalModel.uvCoords.push_back(currentTexCoord);
			normalModel.normals.push_back(currentNormal);
		}
		else
		{
			normalModelIndex = it->second;
		}

		//Create model which properly separates texture coordinates
		unsigned int previousVertexLocation = FindLastVertexIndex(indexLookup, currentIndex, result);

		if (previousVertexLocation == (unsigned int)-1)
		{
			resultModelIndex = result.positions.size();

			result.positions.push_back(currentPosition);
			result.uvCoords.push_back(currentTexCoord);
			result.normals.push_back(currentNormal);
		}
		else
		{
			resultModelIndex = previousVertexLocation;
		}
		normalModel.indices.push_back(normalModelIndex);
		result.indices.push_back(resultModelIndex);
		indexMap.insert(pair<unsigned int, unsigned int>(resultModelIndex, normalModelIndex));
	}

	if (!hasNormals)
	{
		normalModel.CalculateNormals();

		for (unsigned int i = 0; i < result.positions.size(); i++)
		{
			result.normals[i] = normalModel.normals[indexMap[i]];
		}
	}

	return result;
};

void OBJModel::CreateOBJFace(const string line)
{

	vector<string> tokens = SplitString(line, ' ');

	OBJIndices.push_back(ParseOBJIndex(tokens[1], &hasUVs, &hasNormals));
	OBJIndices.push_back(ParseOBJIndex(tokens[2], &hasUVs, &hasNormals));
	OBJIndices.push_back(ParseOBJIndex(tokens[3], &hasUVs, &hasNormals));

	if ((int)tokens.size() > 4)
	{
		OBJIndices.push_back(ParseOBJIndex(tokens[1], &hasUVs, &hasNormals));
		OBJIndices.push_back(ParseOBJIndex(tokens[3], &hasUVs, &hasNormals));
		OBJIndices.push_back(ParseOBJIndex(tokens[4], &hasUVs, &hasNormals));
	}
}

unsigned int OBJModel::FindLastVertexIndex(const vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const ObjIndexedModel& result)
{
	unsigned int start = 0;
	unsigned int end = indexLookup.size();
	unsigned int current = (end - start) / 2 + start;
	unsigned int previous = start;

	while (current != previous)
	{
		OBJIndex* testIndex = indexLookup[current];

		if (testIndex->vertexIndex == currentIndex->vertexIndex)
		{
			unsigned int countStart = current;

			for (unsigned int i = 0; i < current; i++)
			{
				OBJIndex* possibleIndex = indexLookup[current - i];

				if (possibleIndex == currentIndex)
				{
					continue;
				}
				if (possibleIndex->vertexIndex != currentIndex->vertexIndex)
				{
					break;
				}

				countStart--;
			}

			for (unsigned int i = countStart; i < indexLookup.size() - countStart; i++)
			{
				OBJIndex* possibleIndex = indexLookup[current + i];

				if (possibleIndex == currentIndex)
				{
					continue;
				}

				if (possibleIndex->vertexIndex != currentIndex->vertexIndex)
				{
					break;
				}
				else if ((!hasUVs || possibleIndex->uvIndex == currentIndex->uvIndex)
					&& (!hasNormals || possibleIndex->normalIndex == currentIndex->normalIndex))
				{
					Vec3 currentPosition = vertices[currentIndex->vertexIndex];
					Vec2 currentTexCoord;
					Vec3 currentNormal;

					if (hasUVs)
					{
						currentTexCoord = uvs[currentIndex->uvIndex];
					}
					else
					{
						currentTexCoord = Vec2(0, 0);
					}
					if (hasNormals)
					{
						currentNormal = normals[currentIndex->normalIndex];
					}
					else
					{
						currentNormal = Vec3(0, 0, 0);
					}
					for (unsigned int j = 0; j < result.positions.size(); j++)
					{
						if (currentPosition == result.positions[j]
							&& ((!hasUVs || currentTexCoord == result.uvCoords[j])
								&& (!hasNormals || currentNormal == result.normals[j])))
						{
							return j;
						}
					}
				}
			}

			return -1;
		}
		else
		{
			if (testIndex->vertexIndex < currentIndex->vertexIndex)
			{
				start = current;
			}
			else
			{
				end = current;
			}
		}

		previous = current;
		current = (end - start) / 2 + start;
	}

	return -1;
}

OBJModel::OBJIndex OBJModel::ParseOBJIndex(const string token, bool* hasUVs, bool* hasNormals)
{
	unsigned int tokenLength = token.length();
	const char* tokenString = token.c_str();

	unsigned int vertIndexStart = 0;
	unsigned int vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, '/');

	OBJIndex result;
	result.vertexIndex = ParseOBJIndexValue(token, vertIndexStart, vertIndexEnd);
	result.uvIndex = 0;
	result.normalIndex = 0;

	if (vertIndexEnd >= tokenLength)
		return result;

	vertIndexStart = vertIndexEnd + 1;
	vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, '/');

	result.uvIndex = ParseOBJIndexValue(token, vertIndexStart, vertIndexEnd);
	*hasUVs = true;

	if (vertIndexEnd >= tokenLength)
		return result;

	vertIndexStart = vertIndexEnd + 1;
	vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, '/');

	result.normalIndex = ParseOBJIndexValue(token, vertIndexStart, vertIndexEnd);
	*hasNormals = true;

	return result;
}

Vec2 OBJModel::ParseOBJVec2(const string line)
{
	unsigned int tokenLength = line.length();
	const char* tokenString = line.c_str();

	unsigned int vertIndexStart = 3;

	while (vertIndexStart < tokenLength)
	{
		if (tokenString[vertIndexStart] != ' ')
		{
			break;
		}
		vertIndexStart++;
	}

	unsigned int vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, ' ');

	float x = ParseOBJFloatValue(line, vertIndexStart, vertIndexEnd);

	vertIndexStart = vertIndexEnd + 1;
	vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, ' ');

	float y = ParseOBJFloatValue(line, vertIndexStart, vertIndexEnd);

	return Vec2(x, y);
}

Vec3 OBJModel::ParseOBJVec3(const string line)
{
	unsigned int tokenLength = line.length();
	const char* tokenString = line.c_str();

	unsigned int vertIndexStart = 2;

	while (vertIndexStart < tokenLength)
	{
		if (tokenString[vertIndexStart] != ' ')
		{
			break;
		}
		vertIndexStart++;
	}

	unsigned int vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, ' ');

	float x = ParseOBJFloatValue(line, vertIndexStart, vertIndexEnd);

	vertIndexStart = vertIndexEnd + 1;
	vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, ' ');

	float y = ParseOBJFloatValue(line, vertIndexStart, vertIndexEnd);

	vertIndexStart = vertIndexEnd + 1;
	vertIndexEnd = FindIndexOf(vertIndexStart, tokenString, tokenLength, ' ');

	float z = ParseOBJFloatValue(line, vertIndexStart, vertIndexEnd);

	return Vec3(x, y, z);
}

bool CompareOBJIndexPtr(const OBJModel::OBJIndex* a, const OBJModel::OBJIndex* b)
{
	return a->vertexIndex < b->vertexIndex;
}

static inline unsigned int ParseOBJIndexValue(const string& token, unsigned int start, unsigned int end)
{
	return atoi(token.substr(start, end - start).c_str()) - 1;
}

static inline float ParseOBJFloatValue(const string& token, unsigned int start, unsigned int end)
{
	return (float)atof(token.substr(start, end - start).c_str());
}