#include "Input.h"
#include "KeyMap.h"

GLFWwindow* Input::s_Window = nullptr;
std::array<uint8_t, (size_t)Key::Count> Input::s_Current{};
std::array<uint8_t, (size_t)Key::Count> Input::s_Previous{};

void Input::Init(GLFWwindow* window)
{
    s_Window = window;
}

void Input::BeginFrame()
{
    s_Previous = s_Current;
}

void Input::Update()
{
    if (!s_Window)
        return;

    for (size_t i = 0; i < (size_t)Key::Count; ++i)
    {
        Key key = (Key)i;
        int glfwKey = ToGlfwKey(key);
        if (glfwKey == GLFW_KEY_UNKNOWN) 
            continue;

        s_Current[i] = (glfwGetKey(s_Window, glfwKey) == GLFW_PRESS);
    }
}

bool Input::Down(Key key)
{
    return s_Current[(size_t)key];
}

bool Input::Pressed(Key key)
{
    size_t i = (size_t)key;
    return s_Current[i] && !s_Previous[i];
}

bool Input::Released(Key key)
{
    size_t i = (size_t)key;
    return !s_Current[i] && s_Previous[i];
}

