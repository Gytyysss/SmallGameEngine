cmake_minimum_required(VERSION 3.20)
project(TinyEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TinyEngine
    src/main.cpp
    src/Application.cpp
    src/Window.cpp
    external/glad/src/glad.c
    src/EngineTime.cpp
)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(TinyEngine PRIVATE
    src
    external/glad/include
)

target_compile_definitions(TinyEngine PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

target_link_libraries(TinyEngine PRIVATE
    glfw
    OpenGL::GL
)

