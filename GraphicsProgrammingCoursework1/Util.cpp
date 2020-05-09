#include "Util.h"

namespace GraphicsProgramming
{

	SDL_Surface* CreateSurface(unsigned int bytesPerPixel, void* pixels, int width, int height, int depth, int pitch)
	{
		Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (bytesPerPixel == 3) ? 8 : 0;
		rmask = 0xff000000 >> shift;
		gmask = 0x00ff0000 >> shift;
		bmask = 0x0000ff00 >> shift;
		amask = 0x000000ff >> shift;
#else // little endian, like x86
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = (bytesPerPixel == 3) ? 0 : 0xff000000;
#endif
		return SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
	}

	unsigned int FindIndexOf(unsigned int start, const char* str, unsigned int length, char token)
	{
		unsigned int result = start;
		while (result < length)
		{
			result++;
			if (str[result] == token)
			{
				break;
			}
		}

		return result;
	}

	float WithinDistance(Vec3 pos1, Vec3 pos2, float distance)
	{
		//Determine the square of the distance between the two positions.
		float dSquared = SquareValue(pos1.x - pos2.x) + SquareValue(pos1.y - pos2.y) + SquareValue(pos1.z - pos2.z);

		return dSquared <= SquareValue(distance);
	}

	string* LoadText(string filename)
	{
		InputFileStream file;
		file.open(filename.c_str());

		string output;
		string currentLine;
		if (file.is_open())
		{
			while (file.good())
			{
				std::getline(file, currentLine);
				output += currentLine + "\n";
			}
			return new string(output);
		}
		return nullptr;
	}

	int RandomNumber(int min, int max)
	{
		return min + (rand() % (max - min + 1));
	}

	Matrix RemoveTranslation(Matrix mat)
	{
		Mat3 m3 = Mat3(mat);
		return Matrix(m3);
		//TODO: Replace with more efficient method
	}

	vector<string> SplitString(string str, char delimiter)
	{
		vector<string> elems;

		const char* cstr = str.c_str();
		unsigned int strLength = str.length();
		unsigned int start = 0;
		unsigned int end = 0;

		while (end <= strLength)
		{
			while (end <= strLength)
			{
				if (cstr[end] == delimiter)
				{
					break;
				}
				end++;
			}

			elems.push_back(str.substr(start, end - start));
			start = end + 1;
			end = start;
		}

		return elems;
	}

	float SquareValue(float value)
	{
		return value * value;
	}
}