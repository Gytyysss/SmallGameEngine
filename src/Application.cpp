#include "Application.h"
#include "Systems/EngineCore.h"
#include "EngineTime.h"
#include <iostream>

Application::Application()
{
    m_Engine.Init(&m_Running);
}


Application::~Application() = default;

void Application::Run()
{
    Time::Init();

    while (m_Running && !m_Engine.ShouldClose())
    {
        m_Engine.BeginFrame();

        double dt = Time::Tick();
        if (dt > 0.1) dt = 0.1;

        m_Engine.Update(dt);
        m_Engine.Render();
        m_Engine.EndFrame();
    }
}


