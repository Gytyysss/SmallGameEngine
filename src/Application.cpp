#include <glad/glad.h>      
#include <GLFW/glfw3.h>     
#include "Application.h"
#include "Window.h"
#include "EngineTime.h"
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
        double dt = Time::Tick();
        if (dt > 0.1) dt = 0.1;

        Update(dt);
        Render();
    }
}
void Application::Update(double dt)
{
    (void)dt;

    if (glfwGetKey(m_Window->Native(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        m_Running = false;

    m_Window->PollEvents();
}

void Application::Render()
{
    glClearColor(0.1f, 0.12f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_Window->SwapBuffers();
}

