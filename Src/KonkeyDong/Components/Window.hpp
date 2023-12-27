#pragma once

#include <SDL_video.h>

class Window
{
	friend class Graphics;

public:
	Window(const char* title, int width, int height);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	~Window();

	void SetFullscreen(bool fullscreen);
	void SetTitle(const char* title);
	void SetSize(int width, int height);

	inline int GetWidth() { return width; }
	inline int GetHeight() { return height; }

private:
	SDL_Window* pWindow;
	int width;
	int height;
	bool isFullscreen = false;
};
