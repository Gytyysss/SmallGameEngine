#include "Systems/WindowHandling/Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



// GLFW calls this when it encounters an internal error.
static void GlfwErrorCallback(int error, const char* description)
{
    std::cout << "[GLFW ERROR " << error << "] " << description << "\n";
}

Window::Window(int width, int height, const char* title)
{
    glfwSetErrorCallback(GlfwErrorCallback);

    if (!glfwInit()) {
        std::cout << "GLFW init failed\n";
        return;
    }

    m_Handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_Handle) {
        std::cout << "Window create failed\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Handle);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD\n";
        glfwDestroyWindow(m_Handle);
        m_Handle = nullptr;
        glfwTerminate();
        return;
    }

    glfwSwapInterval(1); // VSync ON: limits FPS to monitor refresh, reduces tearing

}

Window::~Window()
{
    if (m_Handle) {
        glfwDestroyWindow(m_Handle);
        glfwTerminate();
    }
}

void Window::PollEvents() { glfwPollEvents(); }
void Window::SwapBuffers() { glfwSwapBuffers(m_Handle); }
bool Window::ShouldClose() const { return glfwWindowShouldClose(m_Handle); }

GLFWwindow* Window::Native() const 
{ 
    return m_Handle; 
}
