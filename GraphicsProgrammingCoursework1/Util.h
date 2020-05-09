#ifndef _UTIL_H
#define _UTIL_H

#include "Aliases.h"
#include "SDL.h"

namespace GraphicsProgramming
{
	SDL_Surface* CreateSurface(unsigned int bytesPerPixel, void* pixels, int width, int height, int depth, int pitch);

	//Find the index of a requested character after a given start point in a string.
	unsigned int FindIndexOf(unsigned int start, const char* str, unsigned int length, char token);

	float WithinDistance(Vec3 pos1, Vec3 pos2, float distance);

	//Return the text stored in the given file path.
	string* LoadText(string filename);

	//Takes two values, returns the largest of them.
	template<typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	//Takes two values, returns the smallest of them.
	template<typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}

	//Returns a random number within the given range.
	int RandomNumber(int min, int max);

	//Remove translation units from the given matrix.
	Matrix RemoveTranslation(Matrix mat);

	//Get a pointer of type T* from a given
	//U*.
	template<class T, class U>
	T* GetPointerOfType(U* ptr)
	{
		return dynamic_cast<T*>(ptr);
		//if (typeid(*ptr) == typeid(T))
		//{
		//	return ((T*)ptr);
		//}
		//return nullptr;
	}

	//Split the given string into multiple
	//substrings using a given character.
	vector<string> SplitString(string str, char delimiter);

	//Multiply the given value by itself and return the result.
	float SquareValue(float value);

}

#endif