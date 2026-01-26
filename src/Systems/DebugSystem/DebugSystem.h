#pragma once

struct GLFWwindow;

class ActionState;

class DebugSystem
{
public:
    void Init(GLFWwindow* window);
    void Shutdown();

    void BeginFrame();
    void Update(const ActionState& actions); 
    void Draw();
    void EndFrame();

private:
    bool m_Inited = false;
    bool m_ShowFPS = true;
};

