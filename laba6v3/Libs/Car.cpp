#include "Car.h"

Car::Car() {
	NumberOfDoors = 0;
	FuelType = "";
}
Car::~Car() {
	NumberOfDoors = 0;
	FuelType = "";
}

int Car::getNumberOfDoors() {
	return this->NumberOfDoors;
}
string Car::getFuelType() {
	return this->FuelType;
}

void Car::setNumberOfDoors(int number) {
	this->NumberOfDoors = number;
}
void Car::setFuelType(string type) {
	this->FuelType = type;
}

string Car::toString() {
	return
		this->owner + "\n" +
		this->reg_number + "\n" +
		this->type + "\n" +
		this->brand + "\n" +
		to_string(this->volume) + "\n" +
		to_string(this->power) + "\n" +
		this->last_to + "\n" +
		to_string(this->mileage) + "\n" + 
		to_string(this->NumberOfDoors) + "\n" +
		this->FuelType + "\n";
}