#include "Application.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <memory>

Application::Application()
{
    m_Window = std::make_unique<Window>(1280, 720, "TinyEngine");
}

void Application::Run()
{
    while (m_Running && m_Window && !m_Window->ShouldClose())
    {
        // Temporary input handling (later replaced by an Input system).
        if (glfwGetKey(m_Window->Native(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_Running = false;

        m_Window->PollEvents();
        m_Window->SwapBuffers();
    }
}
