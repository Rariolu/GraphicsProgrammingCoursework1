//Version number
#version 330 core

in GS_OUT
{
	vec2 texCoord;
	float purple;
} fs_in;

//Unifrom variable
uniform sampler2D diffuse;

void main()
{
	vec4 textureColour = texture2D(diffuse,fs_in.texCoord);
	vec4 p = vec4(0.328125,0.1484375,0.4765625,1);
	textureColour = mix(textureColour,p,fs_in.purple);
	gl_FragColor = textureColour;
}