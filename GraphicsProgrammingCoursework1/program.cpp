#include "Game.h"

#undef main

int main()
{
	return Game::Instance()->CreateWindow(windowTitle, windowWidth, windowHeight);
}