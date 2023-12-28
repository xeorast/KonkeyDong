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
	frequency = SDL_GetPerformanceFrequency();
	ticksPerMicrosecond = frequency / 1e6;

	initialMark = GetTimestamp();
	prevMark = initialMark;
}

kd::time::duration Timer::Peek()
{
	auto now = GetTimestamp();
	return now - prevMark;
}

kd::time::duration Timer::Mark()
{
	auto now = GetTimestamp();
	auto duration = now - prevMark;
	prevMark = now;
	return duration;
}

kd::time::duration Timer::GetTotalTime()
{
	auto now = GetTimestamp();
	return now - initialMark;
}

kd::time::time_point Timer::GetTimestamp()
{
	return time_point::fromMicroseconds(SDL_GetPerformanceCounter() / ticksPerMicrosecond);
}
