#include "Application.h"
#include "Window.h"
#include "Time.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
{
    m_Window = std::make_unique<Window>(1280, 720, "TinyEngine");
}

Application::~Application() = default;

void Application::Run()
{
    Time::Init();

    while (m_Running && m_Window && !m_Window->ShouldClose())
    {
        double raw_dt = Time::Tick();
        double dt = raw_dt;

        if (dt > 0.1) 
            dt = 0.1; //100 milliseconds clamp if delta time exceeds it

        if (glfwGetKey(m_Window->Native(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_Running = false;



        m_Window->PollEvents();
        m_Window->SwapBuffers();
    }
}
