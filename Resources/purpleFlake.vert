//Version Number
#version 330 core

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexCoord;
layout (location = 2) in vec3 VertexNormal;

//Passing out the normal and position data
out VS_OUT
{
	vec3 v_norm;
	vec4 v_pos;
	vec2 texCoord;
	float purple;
	float time;
} vs_out;

uniform mat4 positionMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;
uniform mat4 viewProjection;

//uniform float acceleration;
uniform float time;
uniform vec3 force;

vec3 ApplyForce(vec3 pos, float yOff)
{
	float tOnGround = sqrt(((-2*force.y)*pos.y));

	float t = time < tOnGround ? time : tOnGround;

	float t2 = t*t;
	vec3 offset = ((0.5f)*t2)*force;
	pos = pos + offset;

	vs_out.purple = t / tOnGround;

	return pos;
}

void main()
{
	mat4 model = positionMatrix * rotationMatrix * scaleMatrix;
	mat4 transform = viewProjection * model;

	float yOffset = -positionMatrix[3][1];

	vec3 pos = VertexPosition;
	pos = ApplyForce(pos,yOffset);

	//Assigning the normal and position data
	vs_out.v_norm = VertexNormal;
	vs_out.v_pos = vec4(pos, 1.0);
	vs_out.texCoord = VertexTexCoord;
	vs_out.time = time;
	
	// Sets the position of the current vertex
	gl_Position = transform * vec4(pos, 1.0);
}