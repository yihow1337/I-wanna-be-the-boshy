#include "Imgui.hpp"

void InitImGui(SDL_Window* window, SDL_GLContext gl_context) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // 禁用 ImGui 的默認配置文件保存（可選，避免干擾）
    io.IniFilename = nullptr;

    // 設定 ImGui 的樣式，匹配圖片的顏色風格
    ImGui::StyleColorsDark(); // 從深色主題開始
    ImGuiStyle& style = ImGui::GetStyle();

    // 調整間距和填充以匹配圖片的緊湊風格
    style.WindowPadding = ImVec2(8, 8);
    style.FramePadding = ImVec2(4, 3);
    style.ItemSpacing = ImVec2(8, 4);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.ScrollbarSize = 10.0f;
    style.WindowRounding = 0.0f; // 移除窗口圓角，匹配圖片的直角邊框
    style.FrameRounding = 0.0f; // 移除框架圓角
    style.GrabRounding = 0.0f; // 移除滑塊抓取部分的圓角

    // 設置顏色，匹配圖片的深色主題和藍色高亮
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // 白色文字
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.0f); // 非常深的背景
    style.Colors[ImGuiCol_Border] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f); // 邊框顏色
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f); // 框架背景（如滑塊背景）
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.0f); // 框架懸停
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.0f); // 框架激活
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // 標題欄背景
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f); // 標題欄激活
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // 標題欄折疊
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.0f, 0.5f, 1.0f, 1.0f); // 藍色複選框勾選
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.0f, 0.5f, 1.0f, 1.0f); // 藍色滑塊抓取
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.0f, 0.7f, 1.0f, 1.0f); // 藍色滑塊抓取激活
    style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f); // 按鈕背景
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.0f); // 按鈕懸停
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.0f); // 按鈕激活
    style.Colors[ImGuiCol_Separator] = ImVec4(0.5f, 0.5f, 0.5f, 0.5f); // 分隔線

    // 初始化 ImGui 的 SDL 和 OpenGL3 後端
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void RenderImGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // 保持原始內容，但添加一些元素以測試樣式
    ImGui::Begin("Debug Window");
    ImGui::Text("This is a debug window.");

    // 添加滑塊和複選框以確認樣式效果
    static float test_slider = 50.0f;
    ImGui::SliderFloat("Test Slider", &test_slider, 0.0f, 100.0f, "%.0f");

    static bool test_checkbox = false;
    ImGui::Checkbox("Test Checkbox", &test_checkbox);

    if (ImGui::Button("Test Button")) {
        // 按鈕邏輯（僅用於測試）
    }

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CleanupImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}