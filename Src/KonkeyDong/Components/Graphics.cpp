#include "Graphics.hpp"

#include <SDL.h>
#include <stdio.h>

Graphics::Graphics(Window* pWindow)
	:
	pWindow(pWindow)
{
	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	pRenderer = SDL_CreateRenderer(pWindow->pWindow, -1, 0);
	if (pRenderer == NULL) {
		SDL_Quit();
		printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
		// todo: throw
		return;
	};

	SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(pRenderer);
}

void Graphics::Present()
{
	SDL_RenderPresent(pRenderer);
}

void Graphics::ClearBuffer()
{
	SDL_SetRenderDrawColor( pRenderer, 0, 0, 0, 255 );
	SDL_RenderClear(pRenderer);
}

void Graphics::DrawTexture(Texture* pTexture, SDL_Rect* sourceClip, SDL_Rect* targetPos)
{
	SDL_RenderCopy(pRenderer, pTexture->pTexture, sourceClip, targetPos);
}
