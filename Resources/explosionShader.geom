//Version number
#version 330 core

//Layout qualfier
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

//Passing in texture coordinates
in VS_OUT
{
	vec3 v_norm;
	vec4 v_pos;
    vec2 texCoord;
} gs_in[];

//Passing out texture coordinates
out GS_OUT
{
	vec2 texCoord;
} gs_out;

//Uniform variable
uniform float time;

uniform float explosionMagnitude;

vec4 explode(vec4 position, vec3 normal)
{
	//Amout of explosion
    float magnitude = explosionMagnitude;
	
	//The offset required to force the model to be in its
	//original formation at time index of 0.
	float offset = -1.570796327;
	
	//Direction of explosion, going along normal
    vec3 direction = normal * ((sin(time+offset) + 1.0) / 2.0) * magnitude; 
	//Returning position
    return position + vec4(direction, 0.0);
}

vec3 GetNormal()
{
	//Getting the normal vector of each vertex
   vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   //returns the cross product between the two vectors calculated
   return normalize(cross(a, b));
}

void main()
{
	//Getting normal
    vec3 normal = GetNormal();
    gl_Position = explode(gl_in[0].gl_Position, normal);
    gs_out.texCoord = gs_in[0].texCoord;
	EmitVertex();

    gl_Position = explode(gl_in[1].gl_Position, normal);
    gs_out.texCoord = gs_in[1].texCoord;
	EmitVertex();
    
	gl_Position = explode(gl_in[2].gl_Position, normal);
    gs_out.texCoord = gs_in[2].texCoord;
	EmitVertex();
    
	EndPrimitive();
}