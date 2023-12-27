#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>

#include "Components/Window.hpp"
#include "Components/Graphics.hpp"

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

SDL_Rect CenterRect(int x, int y, int width, int height) {
	return SDL_Rect{
		.x = (int)(x - width / 2.0),
		.y = (int)(y - height / 2.0),
		.w = width,
		.h = height
	};
}

int main(int argsc, char* args[])
{
	Window* pWindow = new Window("Main window", SCREEN_WIDTH, SCREEN_HEIGHT);
	Graphics* pGfx = new Graphics(pWindow);

	Texture* pTexture = new Texture("./assets/soulKeeper.bmp", pGfx);

	double x = SCREEN_WIDTH / 2.0;
	double y = SCREEN_HEIGHT / 2.0;
	double xSpeed = 0;
	double ySpeed = 0;

	int64_t t1 = SDL_GetTicks();
	int64_t t2{};
	bool quit = false;
	while (!quit)
	{
		t2 = SDL_GetTicks();
		double delta = (t2 - t1) * 0.001;
		t1 = t2;

		x += xSpeed * delta;
		y += ySpeed * delta;

		pGfx->ClearBuffer();

		SDL_Rect dest = CenterRect((int)x, (int)y, pTexture->GetWidth(), pTexture->GetHeight());
		pGfx->DrawTexture(pTexture, NULL, &dest);

		pGfx->Present();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
				else if (event.key.keysym.sym == SDLK_UP) ySpeed = -1 * SCREEN_HEIGHT;
				else if (event.key.keysym.sym == SDLK_DOWN) ySpeed = 1 * SCREEN_HEIGHT;
				else if (event.key.keysym.sym == SDLK_RIGHT) xSpeed = 1 * SCREEN_WIDTH;
				else if (event.key.keysym.sym == SDLK_LEFT) xSpeed = -1 * SCREEN_WIDTH;
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) ySpeed = 0;
				else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT) xSpeed = 0;
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
	}

	SDL_Quit();
	return 0;
}
