#pragma once

#include <stdint.h>

namespace kd::time {
	class duration {
	public:
		consteval duration() = default;
		static constexpr duration fromMiliseconds(int64_t miliseconds) { return duration(miliseconds); }
		static constexpr duration fromSeconds(int64_t seconds) { return duration(seconds / 1000); }

		constexpr duration operator-(duration second) const {
			return duration(this->value - second.value);
		}
		constexpr duration operator+(duration second) const {
			return duration(this->value + second.value);
		}

		constexpr int64_t GetMiliseconds() const { return value; }
		constexpr int64_t GetSeconds() const { return value / 1000; }
		constexpr double GetTotalSeconds() const { return value / 1000.0; }

	private:
		constexpr explicit duration(int64_t ticks) :value(ticks) {};
		int64_t value{};
	};

	class time_point {
	public:
		constexpr time_point() = default;
		static constexpr time_point fromMiliseconds(int64_t miliseconds) { return time_point(miliseconds); }
		static constexpr time_point fromSeconds(int64_t seconds) { return time_point(seconds / 1000); }

		constexpr duration operator-(time_point start) const {
			return duration::fromMiliseconds(this->value - start.value);
		}
		constexpr time_point operator+(duration dur) const {
			return fromMiliseconds(this->value + dur.GetMiliseconds());
		}

	private:
		constexpr explicit time_point(int64_t ticks) :value(ticks) {};
		int64_t value{};
	};
}
