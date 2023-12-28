#pragma once

#include <SDL_render.h>

#include "Window.hpp"
#include "Texture.hpp"
#include "Viewport.hpp"


class Graphics
{
	friend class Texture;
public:
	Graphics(Window* pWindow);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void Present();
	void ClearBuffer();

	void DrawTexture(Texture* pTexture, SDL_Rect* sourceClip, SDL_FRect* targetPos);

	inline int GetScreenWidth() { return pWindow->GetWidth(); }
	inline int GetScreenHeight() { return pWindow->GetWidth(); }

	Viewport* const GetViewport() { return pViewport; }

private:
	Window* pWindow;
	Viewport* pViewport;
	SDL_Renderer* pRenderer{};
};
