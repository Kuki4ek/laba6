#pragma once
#include "vechicle.h"
#include <string>
using namespace std;
class Car : public Vehicle {
protected:
	int NumberOfDoors;
	string FuelType;
public:
	Car();
	~Car();
	int getNumberOfDoors();
	string getFuelType();

	void setNumberOfDoors(int);
	void setFuelType(string);

	string toString();
};