#include "EngineTime.h"

std::chrono::steady_clock::time_point Time::s_Last;

void Time::Init()
{
    s_Last = std::chrono::steady_clock::now();
}

double Time::Tick()
{
    const auto now = std::chrono::steady_clock::now();
    const std::chrono::duration<double> dt = now - s_Last;
    s_Last = now;
    return dt.count();
}
