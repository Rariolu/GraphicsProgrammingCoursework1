#ifndef _UTIL_H
#define _UTIL_H

#include "Aliases.h"

//Find the index of a requested character after a given start point in a string.
unsigned int FindIndexOf(unsigned int start, const char* str, unsigned int length, char token);

//Return the text stored in the given file path.
string LoadText(string filename);

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

//Split the given string into multiple
//substrings using a given character.
vector<string> SplitString(string str, char delimiter);

//Multiply the given value by itself and return the result.
float SquareValue(float value);

#endif