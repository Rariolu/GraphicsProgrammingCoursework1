#ifndef _RECS_H
#define _RECS_H

#include "Aliases.h"

namespace GraphicsProgramming
{
	/*map<unsigned int, string> quadMShaders =
	{
		{GL_VERTEX_SHADER,R"str(
#version 120

attribute vec3 position;
attribute vec2 texCoord;

uniform mat4 positionMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;
uniform mat4 viewProjection;

varying vec2 texCoord0;

void main()
{
	mat4 model = positionMatrix * rotationMatrix * scaleMatrix;
	mat4 transform = viewProjection * model;
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}
)str"	},


		{GL_FRAGMENT_SHADER, R"str(
#version 120

varying vec2 texCoord0;

uniform sampler2D diffuse;

void main()
{
	gl_FragColor = texture2D(diffuse, texCoord0);
}
)str"	}
	};*/
}

#endif