#pragma once

#include "../Data/Time.hpp"

class Timer
{
public:
	Timer();

	[[nodiscard]]
	kd::time::duration Peek();
	kd::time::duration Mark();

	[[nodiscard]]
	kd::time::duration GetTotalTime();

private:
	kd::time::time_point GetTimestamp();

	kd::time::time_point initialMark{};
	kd::time::time_point prevMark{};
	int64_t frequency;
	double ticksPerMicrosecond;
};
