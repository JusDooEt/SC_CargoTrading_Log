#include "ShipSelector.h"
#include "imgui.h"

ShipSelectWindow::ShipSelectWindow()
{
	//shipNames = NULL;
	shipListFile = "ShipList.txt";
	shipCount = 0;
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

		string shipsNames[] = { "Crusader, C2 Hercules Starlifter",
								"Crusader, M2 Hercules Starlifter",
								"Crusader, Mercury Star Runner",
								"Drake, Caterpillar",
								"RSI, Constellation Andromeda" };
		//const char* nameList[] = shipsNames.data();
	
		if (ImGui::BeginCombo("combo 1", shipsNames[item_current_idx].c_str(), flags))
		{
			
			for (int n = 0; n < IM_ARRAYSIZE(shipsNames); n++)
			{
				const bool is_selected = (item_current_idx == n);
				if (ImGui::Selectable(shipsNames[n].c_str(), is_selected))
					item_current_idx = n;

				// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();

			
			//ImGui::Text("Cargo Capacity: %d", shipList[item_current_idx].cargoMax);
		}
		ImGui::Text("Ship: %s", shipsNames[item_current_idx].c_str());
	}ImGui::End();
}

void ShipSelectWindow::InitializeShipList()
{
	ifstream fin;
	string name;
	int cargoMax;
	Ship* ptr = NULL;


	fin.open("ShipList.txt");
	
	//shipNames = new char[]
	while (fin)
	{
		getline(fin, name);
		fin >> cargoMax;
		fin.ignore();
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

//void ShipSelectWindow::CountShipList()
//{
//	ifstream fin;
//	fin.open("ShipList.txt");
//
////	shipCount = 0;
//	int input;
//	string strInput;
//	while (fin)
//	{
//		getline(fin, strInput);
//		if(fin >> input)
//		{
//			shipCount++;
//			cout << "Ship found" << shipCount << endl;
//		}
//		fin.ignore();
//	}
//	//cout << "shipCount = " << shipCount;
//
//	fin.close();
//}

