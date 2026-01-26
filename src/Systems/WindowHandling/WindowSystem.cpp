#include "WindowSystem.h"
#include "Window.h"
#include "Input/ActionState.h"
#include "Input/Actions.h"      // kur yra enum Action
#include <GLFW/glfw3.h>
WindowSystem::~WindowSystem() {}

void WindowSystem::Init(int width, int height, const char* title)
{
    m_Window = std::make_unique<Window>(width, height, title);

    // pririšam fullscreen helperį prie realaus GLFW window handle
    m_Fullscreen.Init(m_Window->Native());
}

void WindowSystem::PollEvents()
{
    if (m_Window) m_Window->PollEvents();
}

void WindowSystem::SwapBuffers()
{
    if (m_Window) m_Window->SwapBuffers();
}

bool WindowSystem::ShouldClose() const
{
    return m_Window ? m_Window->ShouldClose() : true;
}

GLFWwindow* WindowSystem::NativeWindow() const
{
    return m_Window ? m_Window->Native() : nullptr;
}

void WindowSystem::Update(const ActionState& actions)
{
    if (actions.Pressed(Action::ToggleFullscreen))
        m_Fullscreen.Toggle();


    if (actions.Pressed(Action::Quit))
         glfwSetWindowShouldClose(NativeWindow(), 1);
}
