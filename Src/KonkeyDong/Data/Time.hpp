#pragma once

#include <stdint.h>

namespace kd::time {
	class duration {
	public:
		consteval duration() = default;
		static constexpr duration fromMicroseconds(int64_t microseconds) { return duration(ticksPerMicrosecond * microseconds); }
		static constexpr duration fromMiliseconds(int64_t miliseconds) { return duration(ticksPerMilisecond * miliseconds); }
		static constexpr duration fromSeconds(int64_t seconds) { return duration(ticksPerSecond * seconds); }

		constexpr duration operator-(duration second) const {
			return duration(this->value - second.value);
		}
		constexpr duration operator+(duration second) const {
			return duration(this->value + second.value);
		}

		constexpr int64_t GetMicroseconds() const { return value / ticksPerMicrosecond; }
		constexpr int64_t GetMiliseconds() const { return value / ticksPerMilisecond; }
		constexpr double GetTotalMiliseconds() const { return value / ticksPerMilisecondD; }
		constexpr int64_t GetSeconds() const { return value / ticksPerSecond; }
		constexpr double GetTotalSeconds() const { return value / ticksPerSecondD; }

	private:
		static constexpr int64_t ticksPerSecond = 1000000;
		static constexpr double ticksPerSecondD = static_cast<double>(ticksPerSecond);
		static constexpr int64_t ticksPerMilisecond = ticksPerSecond / 1000;
		static constexpr double ticksPerMilisecondD = static_cast<double>(ticksPerMilisecond);
		static constexpr int64_t ticksPerMicrosecond = ticksPerMilisecond / 1000;
		constexpr explicit duration(int64_t ticks) :value(ticks) {};
		int64_t value{};
	};

	class time_point {
	public:
		constexpr time_point() = default;
		static constexpr time_point fromMicroseconds(int64_t microseconds) { return time_point(ticksPerMicrosecond * microseconds); }
		static constexpr time_point fromMiliseconds(int64_t miliseconds) { return time_point(ticksPerMilisecond * miliseconds); }
		static constexpr time_point fromSeconds(int64_t seconds) { return time_point(ticksPerSecond * seconds); }

		constexpr duration operator-(time_point start) const {
			return duration::fromMicroseconds(this->getMicroseconds() - start.getMicroseconds());
		}
		constexpr time_point operator+(duration dur) const {
			return fromMicroseconds(this->getMicroseconds() + dur.GetMicroseconds());
		}

	private:
		static constexpr int64_t ticksPerSecond = 1000000;
		static constexpr int64_t ticksPerMilisecond = ticksPerSecond / 1000;
		static constexpr int64_t ticksPerMicrosecond = ticksPerMilisecond / 1000;
		constexpr explicit time_point(int64_t ticks) :value(ticks) {};

		constexpr int64_t getMicroseconds() const { return value / ticksPerMicrosecond; }
		int64_t value{};
	};
}
