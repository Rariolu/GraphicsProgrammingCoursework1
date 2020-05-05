#ifndef _SDLWINDOWMANAGER_H
#define _SDLWINDOWMANAGER_H

#include "SDL.h"
#include "glew.h"
#include "Logger.h"

namespace GraphicsProgramming
{

	class SDLWindowManager
	{
	public:
		//Destroy this instance of "SDLWindowManager",
		//deleting the openGL context and the sdl window
		//in the process.
		~SDLWindowManager();

		//Attempt to create and initialse an SDL window and return true if
		//it succeeds (and return false if it fails). Output the created 
		//instance of "SDLWindowManager".
		static bool GenerateWindowManager(string windowTitle, float width, float height, SDLWindowManager* sdlwindowmanager);

		//Return a pointer to an instance of "SDLWindowManager"
		//(or create one if one hasn't been created yet).
		static SDLWindowManager* Instance();

		//Clear the window so that a colour described by the 
		//RGBA values is the only one onscreen.
		void ClearDisplay(float r, float g, float b, float a);

		//Return the height of the window.
		float GetScreenHeight();

		//Return the width of the window.
		float GetScreenWidth();

		//Swap from the front window buffer to the back
		//window buffer (which becomes the new front buffer).
		void SwapBuffer();

	private:
		//Create a new instance of "SDLWindowManager"
		//(private so that instances can only be created by the
		//"Instance" method).
		SDLWindowManager();

		//Attempt to create and initialse an SDL window and return true if
		//it succeeds (and return false if it fails).
		bool Initialise(string windowTitle, float width, float height);

		//A pointer to the current instance of "SDLWindowManager".
		static SDLWindowManager* instance;
		int i = 4;
		//The height of the window.
		float screenHeight;

		//The width of the window.
		float screenWidth;

		//A pointer to the openGL context.
		SDL_GLContext* openGLContext;

		//A pointer to the "SDL_Window" instance.
		SDL_Window* sdlWindow;
	};

}

#endif
