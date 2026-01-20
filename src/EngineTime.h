#pragma once
#include <chrono>

class Time
{
public:
    static void Init();
    static double Tick();

private:
    static std::chrono::steady_clock::time_point s_Last;
};

