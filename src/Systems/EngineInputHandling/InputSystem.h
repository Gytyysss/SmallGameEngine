#pragma once

#include "Input/ActionState.h"
#include "Input/ActionMap.h"

struct GLFWwindow;

class InputSystem
{
public:
    void Init(GLFWwindow* window);
    void BeginFrame();
    void Update();

    const ActionState& Actions() const { return m_Actions; }

private:
    ActionMap m_Map;
    ActionState m_Actions;
};
