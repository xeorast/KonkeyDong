﻿#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>

#include "Components/Window.hpp"
#include "Components/Graphics.hpp"
#include "Components/Timer.hpp"
#include "GameObjects/Entity.hpp"
#include "Components/Keyboard.hpp"
#include "Components/Viewport.hpp"

using namespace kd::math;

constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 480;

int main(int argsc, char* args[])
{
	Window* pWindow = new Window("Main window", SCREEN_WIDTH, SCREEN_HEIGHT);
	Graphics* pGfx = new Graphics(pWindow);
	Keyboard* pKbd = new Keyboard();

	Viewport* pView = pGfx->GetViewport();
	pView->SetVirtualWidth(40);

	Texture* pTexture = new Texture("./assets/soulKeeper.bmp", pGfx);
	Entity* pPlayer = new Entity(PositionF2(5, 5), SizeF2(10, 10), pTexture);

	const double baseSpeed = 40;

	Timer* timer = new Timer();
	bool quit = false;
	while (!quit)
	{
		// get delta
		double delta = timer->Mark().GetTotalSeconds();

		// handle inputs
		double xSpeed = 0;
		double ySpeed = 0;
		if (pKbd->IsPressed(SDLK_UP)) ySpeed += -1 * baseSpeed;
		if (pKbd->IsPressed(SDLK_DOWN)) ySpeed += 1 * baseSpeed;
		if (pKbd->IsPressed(SDLK_RIGHT)) xSpeed += 1 * baseSpeed;
		if (pKbd->IsPressed(SDLK_LEFT)) xSpeed += -1 * baseSpeed;
		if (pKbd->IsPressed(SDLK_LCTRL)) { xSpeed *= 2; ySpeed *= 2; }
		if (pKbd->IsPressed(SDLK_LSHIFT)) { xSpeed /= 2; ySpeed /= 2; }

		while (pKbd->HasEvent())
		{
			auto& e = pKbd->GetEvent();
			if (e.IsPressKey(SDLK_ESCAPE)) quit = 1;
		}

		// update scene
		Vec2 move(static_cast<float>(xSpeed * delta), static_cast<float>(ySpeed * delta));
		pPlayer->Move(move);

		pGfx->ClearBuffer();

		pPlayer->Draw(pGfx);

		pGfx->Present();

		// pump events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				pKbd->OnClick(event.key.keysym.scancode);
				break;
			case SDL_KEYUP:
				pKbd->OnRelease(event.key.keysym.scancode);
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
	}

	delete pKbd;
	delete pGfx;
	delete pWindow;
	delete pTexture;
	delete pPlayer;

	SDL_Quit();
	return 0;
}
