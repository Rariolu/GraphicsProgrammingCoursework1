#ifndef _INDEXEDMODEL_H
#define _INDEXEDMODEL_H

#include "Aliases.h"

namespace GraphicsProgramming
{

#if BLEP

	class IndexedModel
	{
	public:
		vector<Vec3> positions;
		vector<Vec2> uvCoordinates;
		vector<Vec3> normals;
		vector<unsigned int> indices;

		void CalculateNormals();
	};

#endif

}

#endif