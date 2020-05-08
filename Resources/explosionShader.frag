//Version number
#version 330 core

in GS_OUT
{
	vec2 texCoord;
} fs_in;

//Unifrom variable
uniform sampler2D diffuse;

void main()
{
	vec4 textureColour = texture2D(diffuse,fs_in.texCoord);
	gl_FragColor = textureColour;
}