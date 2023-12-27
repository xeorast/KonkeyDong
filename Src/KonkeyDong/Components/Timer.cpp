#include "Timer.hpp"

#include <SDL.h>
#include <stdio.h>

using namespace kd::time;

void GlobalTimerInit()
{
	static bool wasInit = false;
	if (wasInit) {
		return;
	}

	if (SDL_Init(SDL_INIT_TIMER) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		// todo: throw
		return;
	}

	wasInit = true;
}

Timer::Timer()
{
	GlobalTimerInit();
	initialMark = time_point::fromMiliseconds(SDL_GetTicks64());
	prevMark = initialMark;
}

kd::time::duration Timer::Peek()
{
	auto now = time_point::fromMiliseconds(SDL_GetTicks64());
	return now - prevMark;
}

kd::time::duration Timer::Mark()
{
	auto now = time_point::fromMiliseconds(SDL_GetTicks64());
	auto duration = now - prevMark;
	prevMark = now;
	return duration;
}

kd::time::duration Timer::GetTotalTime()
{
	auto now = time_point::fromMiliseconds(SDL_GetTicks64());
	return now - initialMark;
}
