#pragma once
#include <GLFW/glfw3.h>
#include "Keys.h"
#include <array>

class Input
{
public:
    static void Init(GLFWwindow* window);
    static void BeginFrame();
    static void Update();

    static bool Down(Key key);
    static bool Pressed(Key key);
    static bool Released(Key key);

private:
    static GLFWwindow* s_Window;
    static std::array<uint8_t, (size_t)Key::Count> s_Current;
    static std::array<uint8_t, (size_t)Key::Count> s_Previous;
};

