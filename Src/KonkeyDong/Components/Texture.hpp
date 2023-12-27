#pragma once

#include "Graphics.hpp"

class Texture
{
	friend class Graphics;
public:
	Texture(const char* path, Graphics* pGfx);
	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;
	~Texture();

	inline int GetWidth() { return width; }
	inline int GetHeight() { return height; }

private:
	SDL_Texture* pTexture{};
	Graphics* pGfx;
	int width{};
	int height{};
};
