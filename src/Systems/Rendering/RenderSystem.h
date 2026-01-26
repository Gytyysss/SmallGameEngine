#pragma once

class RenderSystem
{
public:
    void Init();
    void Update(double dt);
    void Render();

private:
    float m_Time = 0.0f;
};
