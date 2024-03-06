#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Ship
{
	string make;
	string model;
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
	void ShowShipData(int id) const;

	// Variable Members
	vector <Ship> shipList;
	string shipListFile;
	int	  shipCount;
};