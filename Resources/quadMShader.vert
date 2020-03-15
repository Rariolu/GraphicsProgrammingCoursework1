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