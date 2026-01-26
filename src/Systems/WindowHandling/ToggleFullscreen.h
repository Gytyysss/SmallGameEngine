#pragma once
#include <GLFW/glfw3.h>

class ToggleFullscreen
{
public:
    void Init(GLFWwindow* window);
    void Toggle();

    bool IsFullscreen() const { return m_Fullscreen; }

private:
    GLFWwindow* m_Window = nullptr;
    bool m_Fullscreen = false;

    int m_WindowedX = 100;
    int m_WindowedY = 100;
    int m_WindowedW = 1280;
    int m_WindowedH = 720;
};
