#include "Game.h"
#include "FlakeIcon.c"

using namespace GraphicsProgramming;

int main(int argc, char* argv[])
{
	return Game::Instance()->CreateWindow(windowTitle, windowWidth, windowHeight, flakeIcon);
}