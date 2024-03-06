#include "Ship.h"

// Ship Constructors & Destructor
Ship::Ship()
{
	name = " ";
	cargoMax = 0;
}

Ship::Ship(std::string name, int cargoMax)
{
	this->name = name;
	this->cargoMax = cargoMax;
}

Ship::~Ship() {}



// Ship Mutators
void Ship::SetName(std::string name)
{
	this->name = name;
}

void Ship::SetCargoMax(int cargoMax)
{
	this->cargoMax = cargoMax;
}



//Ship Accessors
std::string Ship::GetName() const
{
	return name;
}

int Ship::GetCargoMax() const
{
	return cargoMax;
}