#include "ShipSelector.h"
#include "imgui.h"

ShipSelectWindow::ShipSelectWindow()
{
	//shipNames = NULL;
	shipListFile = "ShipList.txt";
	shipCount = 0;
	InitializeShipList();
}

ShipSelectWindow::~ShipSelectWindow()
{
	shipList.clear();
}



void ShipSelectWindow::BeginWindow()
{
	//ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::SetNextWindowPos(ImGui::GetWindowPos());
	ImGui::SetNextWindowSize(ImVec2(784, -1), ImGuiCond_Once);
	static ImGuiComboFlags windowFlags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;
	if(ImGui::Begin("Ships", NULL, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
	{
		float viewPortWidth = ImGui::GetMainViewport()->Size.x;
		float viewPortHeight = ImGui::GetMainViewport()->Size.y;
		cout << "viewPortHeight = " << viewPortHeight << endl;
		//auto win = ImGui::GetCurrentWindowRead();
			// test is the window is in another viewport than the default 
			// and so disable titlebar and resizing (the grip will be hidden, and the resizing feature via imgui will be disabled)
		if (viewPortHeight < ImGui::GetWindowSize().y)
			ImGui::SetWindowSize(ImVec2(ImGui::GetWindowSize().x, viewPortHeight));

		if (viewPortWidth < ImGui::GetWindowSize().x)
			ImGui::SetWindowSize(ImVec2(viewPortWidth, ImGui::GetWindowSize().y));


		static ImGuiComboFlags flags = 0;
		static int item_current_idx = 0;

	
		if (ImGui::BeginCombo("Select a ship", (shipList[item_current_idx].make + ", " + shipList[item_current_idx].model).c_str(), flags))
		{
			
			for (int n = 0; n < shipCount; n++)
			{
				const bool is_selected = (item_current_idx == n);
				if (ImGui::Selectable((shipList[n].make + ", " + shipList[n].model).c_str(), is_selected))
					item_current_idx = n;

				// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
		ImGui::Text("Make: %s", shipList[item_current_idx].make.c_str());
		ImGui::Text("Model: %s", shipList[item_current_idx].model.c_str());
		ImGui::Text("Cargo Capacity: %d SCU", shipList[item_current_idx].cargoMax);
	}ImGui::End();
}

void ShipSelectWindow::InitializeShipList()
{
	ifstream fin;
	string make;
	string model;
	int cargoMax;
	Ship* ptr = NULL;


	fin.open(shipListFile);
	while (fin)
	{
		getline(fin, make);
		getline(fin, model);
		fin >> cargoMax;
		fin.ignore();
		shipCount++;
		ptr = new Ship;
		ptr->make = make;
		ptr->model = model;
		ptr->cargoMax = cargoMax;
		/*cout << "Adding " << ptr->name << " to the ShipList\n"
			<< "Cargo Cap = " << ptr->cargoMax << " SCU\n";*/
		shipList.push_back(*ptr);
		ptr = NULL;
	}
	
	fin.close();

}

//void ShipSelectWindow::ShowShipData(int id) const
//{
//	ImGui::Text("Make: %s", shipList[id].make.c_str());
//	ImGui::Text("Model: %s", shipList[id].model.c_str());
//	ImGui::Text("Cargo Capacity: %d SCU", shipList[id].cargoMax);
//}

