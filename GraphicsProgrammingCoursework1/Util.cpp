#include "Util.h"

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

string LoadText(string filename)
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
	}
	return output;
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