#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Ship
{
	string name;
	int cargoMax;
};

class ShipSelectWindow
{
public:
	ShipSelectWindow();
	~ShipSelectWindow();

	void InitializeShipList();
	void BeginWindow();


private:
	
	//void CountShipList();

	// Variable Members
	vector <Ship> shipList;
	string shipListFile;
	int	  shipCount;
};