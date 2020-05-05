#include "Game.h"

#undef main
using namespace GraphicsProgramming;

int main()
{
	return Game::Instance()->CreateWindow(windowTitle, windowWidth, windowHeight);
}