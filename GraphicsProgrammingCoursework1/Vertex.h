#ifndef _VERTEX_H
#define _VERTEX_H

#include "Aliases.h"

//A struct representing an indiviual mesh vertex.
struct Vertex
{
	public:
		Vertex(Vec3 position, Vec3 normal, Vec2 uv)
		{
			this->normal = new Vec3(normal);
			this->position = new Vec3(position);
			this->uv = new Vec2(uv);
		}
		Vec3* GetNormal()
		{
			return normal;
		}
		Vec3* GetPosition()
		{
			return position;
		}
		Vec2* GetUVCoordinate()
		{
			return uv;
		}
	private:
		Vec3* normal;
		Vec3* position;
		Vec2* uv;
};

#endif