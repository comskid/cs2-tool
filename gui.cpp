void RenderMenu() {
    ImGui::Begin("CS2 Tool", nullptr, ImGuiWindowFlags_NoCollapse);
    
    ImGui::BeginTabBar("Features");
    if (ImGui::BeginTabItem("Aimbot")) {
        ImGui::Checkbox("Enable Aimbot", &config.aimbotEnabled);
        ImGui::SliderFloat("FOV", &config.aimbotFOV, 1.0f, 180.0f);
        ImGui::SliderFloat("Smooth", &config.smoothFactor, 1.0f, 30.0f);
        ImGui::EndTabItem();
    }
    
    if (ImGui::BeginTabItem("ESP")) {
        ImGui::ColorEdit3("Box Color", config.espColor);
        ImGui::Checkbox("Skeleton ESP", &config.skeletonEsp);
        ImGui::EndTabItem();
    }
    ImGui::EndTabBar();
    
    ImGui::End();
}
