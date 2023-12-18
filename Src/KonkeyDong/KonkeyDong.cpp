// KonkeyDong.cpp : Defines the entry point for the application.
//

#include "KonkeyDong.h"

#include <SDL.h>
#include <SDL_main.h>

using namespace std;

int main(int argsc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* pWindow = SDL_CreateWindow("Main window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, 0);

	if (pWindow == NULL) {
		SDL_Quit();
		printf("SDL_CreateWindow error: %s\n", SDL_GetError());
		return 1;
	};

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
	}

	return 0;
}
