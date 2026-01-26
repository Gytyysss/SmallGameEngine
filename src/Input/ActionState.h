#pragma once
#include <array>
#include "Actions.h"

class ActionState
{
public:
    void BeginFrame();
    void SetDown(Action a, bool down);

    bool Down(Action a) const;
    bool Pressed(Action a) const;
    bool Released(Action a) const;

private:
    static constexpr size_t Count = static_cast<size_t>(Action::Count);

    std::array<bool, Count> m_Down{};
    std::array<bool, Count> m_PrevDown{};
};
