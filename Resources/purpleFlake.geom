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

float Lerp(float a, float b, float c)
{
    return a + c * (b - a);
}

vec4 Sway(vec3 normal)
{
	float t = gs_in[0].time;
	float m = 0.25f;

	float xOff = 0.14f;
	float zOff = 0.41f;

	float x = sin(t+xOff)*m;
	float z = sin(t+zOff)*m;

	vec3 v = vec3(x,0,z)*normal;

	return vec4(v,0);
}

float HomogeniseY(float currentY, float lowestY, float t)
{
	float dur = 20;
	float yT = t > dur ? 1 : t/dur;
	return Lerp(currentY, lowestY, yT);
}

void main()
{
	vec3 normal = GetNormal();

	vec4 sway = Sway(normal);

	vec4 p1 = gl_in[0].gl_Position+sway;
	vec4 p2 = gl_in[1].gl_Position+sway;
	vec4 p3 = gl_in[2].gl_Position+sway;

	float lowestY = min(p1.y,min(p2.y,p3.y));
	float t = gs_in[0].time;

	p1.y = HomogeniseY(p1.y, lowestY, t);
	p2.y = HomogeniseY(p2.y, lowestY, t);
	p3.y = HomogeniseY(p3.y, lowestY, t);

    gl_Position = p1;
	gs_out.texCoord = gs_in[0].texCoord;
	gs_out.purple = gs_in[0].purple;
	EmitVertex();

    gl_Position = p2;
	gs_out.texCoord = gs_in[1].texCoord;
	gs_out.purple = gs_in[1].purple;
	EmitVertex();
    
    gl_Position = p3;
	gs_out.texCoord = gs_in[2].texCoord;
	gs_out.purple = gs_in[2].purple;
	EmitVertex();
    
	EndPrimitive();
}