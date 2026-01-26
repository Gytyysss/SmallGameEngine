#pragma once
#include "Window.h"
#include <memory>
#include "Systems/WindowHandling/ToggleFullscreen.h"

struct GLFWwindow;
class Window;
class ActionState; //Input/ActionState.h

class WindowSystem
{
public:
    WindowSystem() = default;
    ~WindowSystem();
    void Init(int width, int height, const char* title);

    void PollEvents();
    void SwapBuffers();
    bool ShouldClose() const;

    void Clear(); // for now: glClearColor + glClear

    GLFWwindow* NativeWindow() const; 
    void Update(const ActionState& actions);


private:
    std::unique_ptr<Window> m_Window;
    ToggleFullscreen m_Fullscreen;

};

