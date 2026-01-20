#pragma once
#include <memory>

class Window;

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
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
};
