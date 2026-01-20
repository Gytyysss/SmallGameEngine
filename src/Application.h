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
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
};
