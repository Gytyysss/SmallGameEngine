#pragma once

class Window;

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    Window* m_Window = nullptr;
    bool m_Running = true;
};
