#ifndef _FONT_H
#define _FONT_H

#include <iostream>
#include <ft2build.h>
#include "Shader.h"
#include FT_FREETYPE_H  

namespace GraphicsProgramming
{
	struct Character
	{
		unsigned int TextureID;  // ID handle of the glyph texture
		glm::ivec2   Size;       // Size of glyph
		glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
		unsigned int Advance;    // Offset to advance to next glyph
	};

	class Font
	{
		public:
			static Font* GetFont(string path);
			void RenderText(string text, float x, float y, float scale, Vec3 colour);
			void SetShader(Shader* shader);
		private:
			Font(FT_Face face, FT_Library ft);
			map<char, Character> characters;
			unsigned int VAO, VBO;
			Shader* textShader;
	};

}

#endif