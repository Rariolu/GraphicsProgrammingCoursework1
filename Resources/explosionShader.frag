//Version number
#version 400

//Unfrom variable
uniform sampler2D diffuse;

in vec2 texCoord;
in vec2 TexCoords;

void main()
{
	vec4 textureColour = texture2D(diffuse,TexCoords);
	gl_FragColor = textureColour;
}