#include "Systems/EngineInputHandling/EngineInputShortcuts.h"
#include "Input/Input.h"
#include "Application.h" // only in cpp

void EngineInputShortcuts::Init(Application* app)
{
    m_App = app;
}

void EngineInputShortcuts::BindPressed(Key key, std::function<void()> fn)
{
    m_OnPressed[key] = std::move(fn);
}

void EngineInputShortcuts::Update()
{
    for (auto& [key, fn] : m_OnPressed)
    {
        if (Input::Pressed(key))
            fn();
    }
}
