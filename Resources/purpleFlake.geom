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
	float purple;
	float time;
} gs_in[];

//Passing out texture coordinates
out GS_OUT
{
	vec2 texCoord;
	float purple;
} gs_out;

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
	vec3 normal = GetNormal();

    gl_Position = gl_in[0].gl_Position;
    gs_out.texCoord = gs_in[0].texCoord;
	gs_out.purple = gs_in[0].purple;
	EmitVertex();

    gl_Position = gl_in[1].gl_Position;
    gs_out.texCoord = gs_in[1].texCoord;
	gs_out.purple = gs_in[1].purple;
	EmitVertex();
    
	gl_Position = gl_in[2].gl_Position;
    gs_out.texCoord = gs_in[2].texCoord;
	gs_out.purple = gs_in[2].purple;
	EmitVertex();
    
	EndPrimitive();
}