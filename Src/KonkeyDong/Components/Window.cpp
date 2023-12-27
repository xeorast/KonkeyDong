#include "Window.hpp"

#include <SDL.h>
#include <stdio.h>

void GlobalVideoInit()
{
	static bool wasInit = false;
	if (wasInit) {
		return;
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		// todo: throw
		return;
	}

	wasInit = true;
}

Window::Window(const char* title, int width, int height)
	:
	width(width),
	height(height)
{
	GlobalVideoInit();

	pWindow = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height,
		0);

	if (pWindow == NULL) {
		SDL_Quit();
		printf("SDL_CreateWindow error: %s\n", SDL_GetError());
		// todo: throw
		return;
	};
}

Window::~Window()
{
	SDL_DestroyWindow(pWindow);
}

void Window::SetFullscreen(bool fullscreen)
{
	int flag = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
	SDL_SetWindowFullscreen(pWindow, flag);
	this->isFullscreen = fullscreen;
}

void Window::SetTitle(const char* title)
{
	SDL_SetWindowTitle(pWindow, title);
}

void Window::SetSize(int width, int height)
{
	SDL_SetWindowSize(pWindow, width, height);
}
