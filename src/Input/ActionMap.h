#pragma once
#include <array>
#include "Actions.h"
#include "Input/Keys.h"

struct ActionBinding
{
    Action action;
    Key key;
};

class ActionMap
{
public:
    static constexpr size_t ActionCount = static_cast<size_t>(Action::Count);

    void SetDefaultBindings()
    {
        m_Bindings[static_cast<size_t>(Action::Quit)] = { Action::Quit, Key::Escape };
        m_Bindings[static_cast<size_t>(Action::ToggleFullscreen)] = { Action::ToggleFullscreen, Key::F11 };
        m_Bindings[static_cast<size_t>(Action::ShowFPS)] = { Action::ShowFPS, Key::F9 };
    }

    const std::array<ActionBinding, ActionCount>& Bindings() const { return m_Bindings; }

private:
    std::array<ActionBinding, ActionCount> m_Bindings{};
};
