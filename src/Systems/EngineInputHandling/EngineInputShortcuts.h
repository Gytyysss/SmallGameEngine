#pragma once

#include <functional>
#include <unordered_map>
#include "Input/Keys.h"

class Application;

class EngineInputShortcuts
{
public:
    void Init(Application* app);
    void BindPressed(Key key, std::function<void()> fn);
    void Update();

private:
    Application* m_App = nullptr;
    std::unordered_map<Key, std::function<void()>> m_OnPressed;
};