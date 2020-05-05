//Version Number
#version 400

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexCoord;
layout (location = 2) in vec3 VertexNormal;

uniform mat4 positionMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;
uniform mat4 viewProjection;

//Passing out the normal and position data
out vec3 v_norm;
out vec4 v_pos; 

out vec2 texCoord;

void main()
{
	mat4 model = positionMatrix * rotationMatrix * scaleMatrix;
	mat4 transform = viewProjection * model;

	//Assigning the normal and position data
	v_norm = VertexNormal;
	v_pos = vec4(VertexPosition, 1.0);

	texCoord = VertexTexCoord;

	// Sets the position of the current vertex
	gl_Position = transform * vec4(VertexPosition, 1.0);
}