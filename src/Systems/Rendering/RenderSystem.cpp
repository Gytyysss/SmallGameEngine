#include "RenderSystem.h"
#include <glad/glad.h>
#include <cmath>

void RenderSystem::Init()
{
    glDisable(GL_DEPTH_TEST);
}

void RenderSystem::Update(double dt)
{
    m_Time += (float)dt; // vienintelis laiko šaltinis
}

void RenderSystem::Render()
{
    float r = 0.5f + 0.5f * std::sin(m_Time);
    float g = 0.5f + 0.5f * std::sin(m_Time + 2.0f);
    float b = 0.5f + 0.5f * std::sin(m_Time + 4.0f);

    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
