#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit()) {
        std::cout << "GLFW init failed\n";
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "TinyEngine", nullptr, nullptr);
    if (!window) {
        std::cout << "Window create failed\n";
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        // ESC = close
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, 1);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
