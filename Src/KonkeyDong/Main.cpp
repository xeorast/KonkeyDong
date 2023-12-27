#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>

#include "Components/Window.hpp"
#include "Components/Graphics.hpp"
#include "Components/Timer.hpp"
#include "GameObjects/Entity.hpp"

using namespace kd::math;

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

int main(int argsc, char* args[])
{
	Window* pWindow = new Window("Main window", SCREEN_WIDTH, SCREEN_HEIGHT);
	Graphics* pGfx = new Graphics(pWindow);

	Texture* pTexture = new Texture("./assets/soulKeeper.bmp", pGfx);
	Entity* player = new Entity(Vec2(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0), pTexture);

	double xSpeed = 0;
	double ySpeed = 0;

	Timer* timer = new Timer();
	bool quit = false;
	while (!quit)
	{
		double delta = timer->Mark().GetTotalSeconds();

		Vec2 move(static_cast<float>(xSpeed * delta), static_cast<float>(ySpeed * delta));
		player->Move(move);

		pGfx->ClearBuffer();

		player->Draw(pGfx);

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
