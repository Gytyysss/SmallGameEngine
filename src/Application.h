#pragma once

#include <memory>
#include "Systems/EngineCore.h"

class Application
{
public:
    Application();
    ~Application();
    void Run();

private:
    void Update(double dt);
    void Render();

private:
    bool m_Running = true;

    EngineCore m_Engine;

};
