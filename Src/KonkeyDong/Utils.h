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

inline SDL_FRect CreateCenterFRect(float x, float y, float width, float height) {
	return SDL_FRect{
		.x = x - width / 2.0f,
		.y = y - height / 2.0f,
		.w = width,
		.h = height
	};
}