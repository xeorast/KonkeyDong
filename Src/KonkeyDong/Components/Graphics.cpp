#include "Graphics.hpp"

#include <SDL.h>
#include <stdio.h>

using namespace kd::math;

Graphics::Graphics(Window* pWindow)
	:
	pWindow(pWindow)
{
	float winWidth = static_cast<float>(pWindow->GetWidth());
	pViewport = new Viewport(winWidth / pWindow->GetHeight(), winWidth, winWidth);

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
	delete pViewport;
}

void Graphics::Present()
{
	SDL_RenderPresent(pRenderer);
}

void Graphics::ClearBuffer()
{
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);
}

void Graphics::DrawTexture(Texture* pTexture, SDL_Rect* sourceClip, SDL_FRect* targetPos)
{
	PositionF2 virtPos(targetPos->x, targetPos->y);
	PositionF2 viewPos = pViewport->VirtualToScreenspacePos(virtPos);

	SDL_FRect targetViewRect{
		.x = viewPos.X,
		.y = viewPos.Y,
		.w = pViewport->VirtualToScreenspaceSize(targetPos->w),
		.h = pViewport->VirtualToScreenspaceSize(targetPos->h)
	};

	SDL_RenderCopyF(pRenderer, pTexture->pTexture, sourceClip, &targetViewRect);
}
