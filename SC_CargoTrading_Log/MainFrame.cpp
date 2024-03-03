#include "MainFrame.h"
#include "Ship.h"
#include <wx/wx.h>
//#include <wx/spinctrl.h>



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//string shipName;
	//string shipCargo;

//	shipInfo = new Ship();

	wxPanel* panel = new wxPanel(this);
	wxArrayString ships;
	ships.Add("Crusader, C2 Hercules");
	/* TO-DO 
		Add more cargo ships */

	//choices.Add("Crusader, A2 Hercules");
	//choices.Add("Crusader, M2 Hercules");
	//choices.Add("Misc, Hull-A");

	wxChoice* shipMenu = new wxChoice(panel, wxID_ANY, wxPoint(325, -1), wxSize(150, -1), ships, wxCB_SORT);
	shipMenu->Select(0);


	//shipMenu->Bind(wxEVT_CHOICE, &MainFrame::OnShipChoice, this);

	/*shipName = ("Ship: %s", shipInfo->GetName());
	shipCargo = ("Cargo Capacity: %d", shipInfo->GetCargoCap());*/
	//wxPanel* shipDataPanel = new wxPanel(panel, wxID_ANY,
	//									wxPoint(-1, 20), wxSize(400, 100), wxCENTER_FRAME);

	//wxStaticText* shipDataText = new wxStaticText(panel, wxID_ANY, "Ship: C2", wxPoint(10, 25));
	CreateStatusBar();
}


//void MainFrame::OnShipChoice(wxCommandEvent& evt)
//{
//	ShipData(evt.GetSelection());
//}
//
//void MainFrame::ShipData(int selection)
//{
//	int cargoCap = 0;
//	string name = "";
//	name = "C2";
//	cargoCap = 696;
//
//	shipInfo->SetCargoCap(cargoCap);
//	shipInfo->SetName(name);
//}