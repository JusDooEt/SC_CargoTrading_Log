#include "Test.h"

#include "imgui.h"

namespace Test
{
    // Declare and initializes window variables (event variables)
    bool testbool = false;
    int  intTest = 10;
    float floatTest = 5.5f;

	void RunTest()
	{

        ImGui::SetNextWindowSize(ImVec2(500, 500));
        //      ImGui::SetNextWindowPos(ImVec2(0, 0));
        if (ImGui::Begin("Test", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse))
        {
            ImGui::Checkbox("Test Bool", &testbool);
            if (ImGui::Button("Click me!"))
            {
                testbool = true;
            }
            ImGui::Text("Int");
            ImGui::SliderInt("##d", &intTest, 1, 25);
            ImGui::Text("Float");
            ImGui::SliderFloat("##dd", &floatTest, 0.1f, 15.5f);
            ImGui::SetCursorPos(ImVec2(400, 100));
            if (ImGui::Button("Test", ImVec2(50, 50)))
            {

            }
        }ImGui::End();

        if (testbool || intTest == 25 || floatTest == 15.5f)
        {
            ImGui::SetNextWindowSize(ImVec2(200, 200));
            if (ImGui::Begin("window w"))
            {

            }ImGui::End();
        }
	}
}