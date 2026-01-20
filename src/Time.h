#pragma once
#include <chrono>

class Time
{
public:
	using Clock = std::chrono::steady_clock;

	static void Init()
	{
		s_Last = Clock::now();
	}

	// Returns seconds since last frame (dt)
	static double Tick()
	{
		const auto now = Clock::now();
		const std::chrono::duration<double> dt = now - s_Last;
		s_Last = now;
		return dt.count();
	}

private:
	inline static Clock::time_point s_Last{};
};

