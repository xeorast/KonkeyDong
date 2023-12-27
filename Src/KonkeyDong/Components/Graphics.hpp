#pragma once

#include <SDL_render.h>

#include "Window.hpp"
#include "Texture.hpp"


class Graphics
{
	friend class Texture;
public:
	Graphics(Window* window);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void Present();
	void ClearBuffer();

	void DrawTexture(Texture* pTexture, SDL_Rect* sourceClip, SDL_Rect* targetPos);

	inline int GetScreenWidth() { return pWindow->GetWidth(); }
	inline int GetScreenHeight() { return pWindow->GetWidth(); }

private:
	Window* pWindow;
	SDL_Renderer* pRenderer{};
};
