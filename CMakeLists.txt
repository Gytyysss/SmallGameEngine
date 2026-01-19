cmake_minimum_required(VERSION 3.20)
project(TinyEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TinyEngine src/main.cpp "src/Application.h" "src/Application.cpp" "src/Window.h" "src/Window.cpp")

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(TinyEngine PRIVATE glfw)
