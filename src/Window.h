#pragma once
struct GLFWwindow;

class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    void PollEvents();
    void SwapBuffers();
    bool ShouldClose() const;

    GLFWwindow* Native() const; // Escape hatch: raw handle for direct GLFW calls (temporary)

private:
    GLFWwindow* m_Handle = nullptr;
};
