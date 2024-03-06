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
	ImGui::SetNextWindowPos(ImVec2(0, 23));
	if(ImGui::Begin("Ships", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDocking))
	{
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

