#include "Ship.h"

// Constructor & Destructor
Ship::Ship()
{
	name = "";
	cargoCap = 0;
	type = C2;

}

Ship::Ship(std::string name, int cargoCap, ShipType type)
{
	this->name = name;
	this->cargoCap = cargoCap;
	this->type = type;
}

Ship::~Ship() {}


// Mutators
void Ship::SetName(std::string name)
{
	this->name = name;
}

void Ship::SetCargoCap(int cargoCap)
{
	this->cargoCap = cargoCap;
}

void Ship::SetType(ShipType type)
{
	this->type = type;
}



// Accessors
std::string Ship::GetName() const
{
	return name;
}

int Ship::GetCargoCap() const
{
	return cargoCap;
}

ShipType Ship::GetType() const
{
	return type;
}