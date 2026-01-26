#include "EngineCore.h"
#include <cstdio>



void EngineCore::Init(bool* running)
{
    m_Running = running;

    m_Window.Init(1280, 720, "TinyEngine");      
    m_Input.Init(m_Window.NativeWindow());
    m_Debug.Init(m_Window.NativeWindow());
}

void EngineCore::Shutdown()
{
    m_Debug.Shutdown();
}


bool EngineCore::ShouldClose() const
{
    return m_Window.ShouldClose();
}

void EngineCore::BeginFrame()
{
    m_Window.PollEvents();
    m_Input.BeginFrame(); // always after PollEvents

}

void EngineCore::Update(double dt)
{
    m_Input.Update();
    m_Window.Update(m_Input.Actions()); // Listen to window input actions
    m_Render.Update(dt);
    m_Debug.Update(m_Input.Actions());

}

void EngineCore::Render()
{
    m_Render.Render();

    m_Debug.BeginFrame();   
    m_Debug.Draw();         
    m_Debug.EndFrame();    
}


void EngineCore::EndFrame()
{
    m_Window.SwapBuffers();
}
