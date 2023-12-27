#include "Texture.hpp"

#include <SDL.h>
#include <stdio.h>

Texture::Texture(const char* path, Graphics* pGfx)
	:
	pGfx(pGfx)
{
	SDL_Surface* pSurface = SDL_LoadBMP(path);
	if (pSurface == NULL) {
		printf("SDL_LoadBMP(\"%s\") error: %s\n", path, SDL_GetError());
		SDL_Quit();
		// todo: throw
		return;
	};

	pTexture = SDL_CreateTextureFromSurface(pGfx->pRenderer, pSurface);
	SDL_FreeSurface(pSurface);
	pSurface = nullptr;

	SDL_SetTextureBlendMode(pTexture, SDL_BLENDMODE_BLEND);
	SDL_QueryTexture(pTexture, NULL, NULL, &width, &height);
}

Texture::~Texture()
{
	SDL_DestroyTexture(pTexture);
}
