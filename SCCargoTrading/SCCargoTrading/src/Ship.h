#pragma once

#include <string>
#include <iostream>

class Ship
{
public:
	// Constructors & Destructor
	Ship();
	Ship(std::string name, int cargoMax);
	~Ship();

	// Mutators
	void SetName(std::string name);
	void SetCargoMax(int cargoMax);

	// Accessors
	std::string GetName() const;
	int GetCargoMax() const;

protected:
	std::string name;
	int cargoMax;
};

