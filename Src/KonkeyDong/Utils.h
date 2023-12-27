#pragma once

#include <SDL_rect.h>

inline SDL_Rect CreateCenterRect(int x, int y, int width, int height) {
	return SDL_Rect{
		.x = (int)(x - width / 2.0),
		.y = (int)(y - height / 2.0),
		.w = width,
		.h = height
	};
}