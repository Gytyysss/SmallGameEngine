#include "ActionState.h"

static size_t Idx(Action a)
{
    return static_cast<size_t>(a);
}

void ActionState::BeginFrame()
{
    m_PrevDown = m_Down;
}

void ActionState::SetDown(Action a, bool down)
{
    const size_t i = Idx(a);
    if (i >= Count) return;          // <-- svarbiausia
    m_Down[i] = down;
}

bool ActionState::Down(Action a) const
{
    const size_t i = Idx(a);
    if (i >= Count) return false;
    return m_Down[i];
}

bool ActionState::Pressed(Action a) const
{
    const size_t i = Idx(a);
    if (i >= Count) return false;
    return m_Down[i] && !m_PrevDown[i];
}

bool ActionState::Released(Action a) const
{
    const size_t i = Idx(a);
    if (i >= Count) return false;
    return !m_Down[i] && m_PrevDown[i];
}
