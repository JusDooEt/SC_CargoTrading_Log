#pragma once
#include <wx/wx.h>


enum ShipType
{
	C2
};

class Ship
{
public:
	// Constructor & Destructor
	Ship();
	Ship(std::string name, int cargoCap, ShipType type);
	~Ship();

	// Mutators
	void SetName(std::string name);
	void SetCargoCap(int cargoCap);
	void SetType(ShipType type);

	// Accessors
	std::string GetName() const;
	int GetCargoCap() const;
	ShipType GetType() const;

private:
	std::string name;
	int cargoCap;
	ShipType type;
};

