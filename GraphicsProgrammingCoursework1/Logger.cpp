#include "Logger.h"

#include <iostream>

void Log(string str)
{
	Log(str.c_str());
}

void Log(const char* cstr)
{
	//Uses regular cout output, but this could
	//be replaced with something else when
	//necessary.
	std::cout << cstr << std::endl;
}