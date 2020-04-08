//Version number
#version 400

//Unfrom variable
uniform float randColourX;
uniform float randColourY;
uniform float randColourZ;
uniform float mixingDegree;
uniform sampler2D diffuse;

in vec2 texCoord;
in vec2 TexCoords;

void main()
{
//Setting each vector component to uniform varaible then setting final colour
	vec4 color = vec4(randColourX,randColourY,randColourZ,1.0);
	
	vec4 textureColour = texture2D(diffuse,TexCoords);
	gl_FragColor = mix(textureColour,color,mixingDegree);
	gl_FragColor = textureColour;
}