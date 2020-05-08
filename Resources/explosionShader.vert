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
} vs_out;

uniform mat4 positionMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;
uniform mat4 viewProjection;

void main()
{
	mat4 model = positionMatrix * rotationMatrix * scaleMatrix;
	mat4 transform = viewProjection * model;

	//Assigning the normal and position data
	vs_out.v_norm = VertexNormal;
	vs_out.v_pos = vec4(VertexPosition,1.0);
	vs_out.texCoord = VertexTexCoord;
	
	// Sets the position of the current vertex
	gl_Position = transform * vec4(VertexPosition, 1.0);
}