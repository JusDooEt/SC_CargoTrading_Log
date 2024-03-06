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
	if(ImGui::Begin("Ships"))
	{
		static ImGuiComboFlags flags = 0;
		static int item_current_idx = 0;

	
		if (ImGui::BeginCombo("Select a ship", shipList[item_current_idx].name.c_str(), flags))
		{
			
			for (int n = 0; n < shipCount; n++)
			{
				const bool is_selected = (item_current_idx == n);
				if (ImGui::Selectable(shipList[n].name.c_str(), is_selected))
					item_current_idx = n;

				// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();

			
			//ImGui::Text("Cargo Capacity: %d", shipList[item_current_idx].cargoMax);
		}
		ImGui::Text("Ship: %s", shipList[item_current_idx].name.c_str());
		ImGui::Text("Cargo Capacity: %d", shipList[item_current_idx].cargoMax);
	}ImGui::End();
}

void ShipSelectWindow::InitializeShipList()
{
	ifstream fin;
	string name;
	int cargoMax;
	Ship* ptr = NULL;


	fin.open("ShipList.txt");
	while (fin)
	{
		getline(fin, name);
		fin >> cargoMax;
		fin.ignore();
		shipCount++;
		ptr = new Ship;
		ptr->cargoMax = cargoMax;
		ptr->name = name;
		cout << "Adding " << ptr->name << " to the ShipList\n"
			<< "Cargo Cap = " << ptr->cargoMax << " SCU\n";
		shipList.push_back(*ptr);
		ptr = NULL;
	}
	
	fin.close();

}



