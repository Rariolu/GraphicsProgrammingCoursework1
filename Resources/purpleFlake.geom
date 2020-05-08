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

vec4 Sway(vec3 normal)
{
	float t = gs_in[0].time;
	float m = 0.025f;

	float xOff = 0.14f;
	float zOff = 0.41f;

	float x = sin(t+xOff)*m;
	float z = sin(t+zOff)*m;

	vec3 v = vec3(x,0,z)*normal;

	return vec4(v,0);
}

vec3 GetNormal()
{
	//Getting the normal vector of each vertex
   vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
   vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
   //returns the cross product between the two vectors calculated
   return normalize(cross(a, b));
}

float Lerp( float a, float b, float c)
{
    return a + c * (b - a);
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
	float yT = t / 10f;
	yT = yT > 1 ? 1 : yT;
	//p1.y = lowestY;
	//p2.y = lowestY;
	//p3.y = lowestY;
	p1.y = Lerp(p1.y, lowestY, yT);
	p2.y = Lerp(p2.y, lowestY, yT);
	p3.y = Lerp(p3.y, lowestY, yT);

    //gl_Position = gl_in[0].gl_Position+sway;
    gl_Position = p1;
	gs_out.texCoord = gs_in[0].texCoord;
	gs_out.purple = gs_in[0].purple;
	EmitVertex();

    //gl_Position = gl_in[1].gl_Position+sway;
    gl_Position = p2;
	gs_out.texCoord = gs_in[1].texCoord;
	gs_out.purple = gs_in[1].purple;
	EmitVertex();
    
	//gl_Position = gl_in[2].gl_Position+sway;
    gl_Position = p3;
	gs_out.texCoord = gs_in[2].texCoord;
	gs_out.purple = gs_in[2].purple;
	EmitVertex();
    
	EndPrimitive();
}