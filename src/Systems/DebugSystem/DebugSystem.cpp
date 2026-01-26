#include "DebugSystem.h"

#include <GLFW/glfw3.h>                      // needed for GLFWwindow*
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Input/ActionState.h"
#include "Input/Actions.h"

void DebugSystem::Init(GLFWwindow* window)
{
    if (m_Inited) return;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    m_Inited = true;
}

void DebugSystem::Shutdown()
{
    if (!m_Inited) return;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    m_Inited = false;
}

void DebugSystem::BeginFrame()
{
    if (!m_Inited) return;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void DebugSystem::Update(const ActionState& actions)
{
    if (!m_Inited) return;

    if (actions.Pressed(Action::ShowFPS))
        m_ShowFPS = !m_ShowFPS;
}

void DebugSystem::Draw()
{
    if (!m_ShowFPS) return;

    const ImGuiViewport* vp = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(vp->WorkPos.x, vp->WorkPos.y), ImGuiCond_Always);

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_AlwaysAutoResize |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoFocusOnAppearing |
        ImGuiWindowFlags_NoNav;

    ImGui::Begin("FPS", nullptr, flags);
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();
}

void DebugSystem::EndFrame()
{
    if (!m_Inited) return;

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

