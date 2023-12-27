#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

int main(int argsc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* pWindow = SDL_CreateWindow("Main window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (pWindow == NULL) {
		SDL_Quit();
		printf("SDL_CreateWindow error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

	SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	if (pRenderer == NULL) {
		SDL_Quit();
		printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_Surface* pSurface = SDL_LoadBMP("./assets/soulKeeper.bmp");
	if (pSurface == NULL) {
		printf("SDL_LoadBMP(\"./assets/soulKeeper.bmp\") error: %s\n", SDL_GetError());
		SDL_DestroyWindow(pWindow);
		SDL_DestroyRenderer(pRenderer);
		SDL_Quit();
		return 1;
	};

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
	SDL_SetTextureBlendMode(pTexture, SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(pSurface);
	pSurface = nullptr;

	int textureWidth{};
	int textureHeight{};
	SDL_QueryTexture(pTexture, NULL, NULL, &textureWidth, &textureHeight);

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

		SDL_RenderClear(pRenderer);

		SDL_Rect dest{};
		dest.x = (int)(x - textureWidth / 2.0);
		dest.y = (int)(y - textureHeight / 2.0);
		dest.w = textureWidth;
		dest.h = textureHeight;
		SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);

		SDL_RenderPresent(pRenderer);


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

	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	SDL_Quit();
	return 0;
}
