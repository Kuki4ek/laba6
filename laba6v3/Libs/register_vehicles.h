#ifndef REGISTER_VEHICLES_H
#define REGISTER_VEHICLES_H
#include "vechicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include <string>
using namespace std;

class RegisterVehicles {
private:
	int max_num_vehicles;
	int num_vehicles;
	int num_cars;
	int num_motorcycles;
	Vehicle *list;
	Car* cars;
	Motorcycle *motorcycles;
public:
	RegisterVehicles(int max_v);
	~RegisterVehicles();
	int AddVehicle(Vehicle v);
	int AddVehicle(Car v);
	int AddVehicle(Motorcycle v);
	void ReadFromFile();
	void WriteToFile();
	void DisplayAll();
	void DisplayById(int id_vehicle);
	void DeleteVehicleById(int id_vehicle);
	void SetList(Vehicle* v);
	Vehicle* GetList();
	void Task1();
	void Task2();
	void SetNumVehicles(int num);
};


#endif
