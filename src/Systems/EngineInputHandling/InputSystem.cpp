#include "InputSystem.h"
#include "Input/Input.h"

void InputSystem::Init(GLFWwindow* window)
{
    Input::Init(window);
    m_Map.SetDefaultBindings();
}

void InputSystem::BeginFrame()
{
    Input::BeginFrame();
    m_Actions.BeginFrame();
}

void InputSystem::Update()
{
    Input::Update();

    //Fill the ActionState based on mapping
    for (const auto& b : m_Map.Bindings())
        m_Actions.SetDown(b.action, Input::Down(b.key));
}
