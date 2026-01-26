#include "Systems/WindowHandling/ToggleFullscreen.h"

void ToggleFullscreen::Init(GLFWwindow* window)
{
    m_Window = window;
}

void ToggleFullscreen::Toggle()
{
    if (!m_Window) return;

    m_Fullscreen = !m_Fullscreen;

    if (m_Fullscreen)
    {
        glfwGetWindowPos(m_Window, &m_WindowedX, &m_WindowedY);
        glfwGetWindowSize(m_Window, &m_WindowedW, &m_WindowedH);

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        glfwSetWindowMonitor(
            m_Window, monitor,
            0, 0,
            mode->width, mode->height,
            mode->refreshRate
        );
    }
    else
    {
        glfwSetWindowMonitor(
            m_Window, nullptr,
            m_WindowedX, m_WindowedY,
            m_WindowedW, m_WindowedH,
            0
        );
    }
}
