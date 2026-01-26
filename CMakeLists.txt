cmake_minimum_required(VERSION 3.20)
project(TinyEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TinyEngine
    src/main.cpp
    src/Application.cpp
    src/EngineTime.cpp

    external/glad/src/glad.c

    src/Input/Input.cpp
    src/Input/KeyMap.cpp

    src/Systems/EngineInputHandling/EngineInputShortcuts.cpp

    src/Systems/WindowHandling/Window.cpp
    src/Systems/WindowHandling/WindowSystem.cpp
    src/Systems/WindowHandling/ToggleFullscreen.cpp
    src/Systems/EngineCore.cpp
 "src/Systems/Rendering/RenderSystem.h" "src/Systems/Rendering/RenderSystem.cpp" "src/Systems/EngineInputHandling/InputSystem.h" "src/Systems/EngineInputHandling/InputSystem.cpp" "src/Input/Actions.h" "src/Input/ActionState.h" "src/Input/ActionState.cpp" "src/Input/ActionMap.h" "src/Systems/DebugSystem/DebugSystem.cpp")

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(TinyEngine PRIVATE
    src
    external/glad/include
    external/imgui
    external/imgui/backends
)

target_sources(TinyEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/external/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/backends/imgui_impl_opengl3.cpp
)

target_compile_definitions(TinyEngine PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

target_link_libraries(TinyEngine PRIVATE
    glfw
    OpenGL::GL
)



