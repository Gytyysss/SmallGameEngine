#pragma once
#include "Systems/WindowHandling/WindowSystem.h"
#include "Systems/Rendering/RenderSystem.h"
#include "Systems/EngineInputHandling/InputSystem.h"
#include "Systems/DebugSystem/DebugSystem.h"

class EngineCore
{
public:
    void Init(bool* running);
    void Shutdown();
    bool ShouldClose() const;
    void BeginFrame();
    void Update(double dt);
    void Render();
    void EndFrame();

private:
    bool* m_Running = nullptr;

    // owns systems (by value is ok now)
    WindowSystem m_Window;
    RenderSystem m_Render;
    InputSystem m_Input;
    DebugSystem m_Debug;

};
