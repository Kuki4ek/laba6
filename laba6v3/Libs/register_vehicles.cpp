#include "register_vehicles.h"
#include "file_proccessor.h"
#include "parser.h"
#include "other_functions.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#define INDENTATION 16
#define VEHICLES "vehicles.txt"
#define CARS "cars.txt"
#define MOTORCYCLES "motorcycles.txt"
using namespace std;
RegisterVehicles::RegisterVehicles(int max_v) {
	max_num_vehicles = max_v;
	list = new Vehicle[max_num_vehicles];
	cars = new Car[max_num_vehicles];
	motorcycles = new Motorcycle[max_num_vehicles];
	num_vehicles = 0;
	num_cars = 0;
	num_motorcycles = 0;
}
RegisterVehicles::~RegisterVehicles() {
	max_num_vehicles = 0;
	delete[] list;
	delete[] cars;
	delete[] motorcycles;
	num_vehicles = 0;
	num_cars = 0;
	num_motorcycles = 0;
}
int RegisterVehicles::AddVehicle(Vehicle v) {
	/*
		0 - ЛИМИТ ПРИВЫШЕН
		1 - Всё ок
	*/
	int flag;
	if (num_vehicles < max_num_vehicles) {
		list[num_vehicles] = v;
		num_vehicles++;
		flag = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}
int RegisterVehicles::AddVehicle(Car v) {
	/*
		0 - ЛИМИТ ПРИВЫШЕН
		1 - Всё ок
	*/
	int flag;
	if (num_cars < max_num_vehicles) {
		list[num_cars] = v;
		num_cars++;
		flag = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}
int RegisterVehicles::AddVehicle(Motorcycle v) {
	/*
		0 - ЛИМИТ ПРИВЫШЕН
		1 - Всё ок
	*/
	int flag;
	if (num_motorcycles < max_num_vehicles) {
		list[num_motorcycles] = v;
		num_motorcycles++;
		flag = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}
void RegisterVehicles::ReadFromFile() {
	string data = "";
	string* dataArr;
	string delimeter = "---\n";
	int count = 0;
	data = FileProccessor::ReadFile(VEHICLES);
	dataArr = Parser::Split(data, delimeter, count);
	for (int i = 0; i < count; i++) {
		list[i] = Parser::ParseStringToVechicle(dataArr[i]);
	}
	num_vehicles = count;

	string* dataArrCar;
	count = 0;
	data = FileProccessor::ReadFile(CARS);
	dataArrCar = Parser::Split(data, delimeter, count);
	for (int i = 0; i < count; i++) {
		cars[i] = Parser::ParseStringToCar(dataArrCar[i]);
	}
	num_cars = count;

	string* dataArrMotorcycle;
	count = 0;
	data = FileProccessor::ReadFile(MOTORCYCLES);
	dataArrMotorcycle = Parser::Split(data, delimeter, count);
	for (int i = 0; i < count; i++) {
		motorcycles[i] = Parser::ParseStringToMotorcycle(dataArrMotorcycle[i]);
	}
	num_motorcycles = count;
}
void RegisterVehicles::WriteToFile() {
	if (num_vehicles == 0 && num_cars == 0 && num_motorcycles == 0) {
		cout << "В буфере нет данных. Ввод в файл невозможен.";
		return;
	}
	string resultStr = "";
	string delimeter = "---\n";
	for (int i = 0; i < num_vehicles; ++i) {
		resultStr += list[i].toString();
		if (i < num_vehicles - 1) {
			resultStr += delimeter;
		}
	}
	FileProccessor::WriteFile(resultStr, VEHICLES);

	resultStr = "";
	for (int i = 0; i < num_cars; ++i) {
		resultStr += cars[i].toString();
		if (i < num_cars - 1) {
			resultStr += delimeter;
		}
	}
	FileProccessor::WriteFile(resultStr, CARS);

	resultStr = "";
	for (int i = 0; i < num_motorcycles; ++i) {
		resultStr += motorcycles[i].toString();
		if (i < num_motorcycles - 1) {
			resultStr += delimeter;
		}
	}
	FileProccessor::WriteFile(resultStr, MOTORCYCLES);
}
void RegisterVehicles::DisplayAll() {
	/*if (num_vehicles == 0) {
		cout << "Записей нет, сначала считайте из файла или введите с клавиатуры!" << endl;
		return; 
	}*/
	cout << "Записей " << num_vehicles << "/" << max_num_vehicles << "." << endl;
	cout << setw(3) << "ID"
		<< setw(INDENTATION) << "Владелец"
		<< setw(INDENTATION) << "Номер"
		<< setw(INDENTATION) << "Тип"
		<< setw(INDENTATION) << "Марка"
		<< setw(INDENTATION) << "Объём двигателя"
		<< setw(INDENTATION) << "Мощность"
		<< setw(INDENTATION) << "Последнее ТО"
		<< setw(INDENTATION) << "Пробег" << endl;
	for (int i = 0; i < num_vehicles; i++) {
		cout << setw(3) << i
			<< setw(INDENTATION) << list[i].getVehicleName()
			<< setw(INDENTATION) << list[i].getVehicleRegNumber()
			<< setw(INDENTATION) << list[i].getVehicleType()
			<< setw(INDENTATION) << list[i].getVehicleBrand()
			<< setw(INDENTATION) << list[i].getVehicleVolume()
			<< setw(INDENTATION) << list[i].getVehiclePower()
			<< setw(INDENTATION) << list[i].getVehicleLastTo()
			<< setw(INDENTATION) << list[i].getVehicleMileage()
			<< endl;
	}

	cout << "Записей " << num_cars << "/" << max_num_vehicles << "." << endl;
	cout << setw(3) << "ID"
		<< setw(INDENTATION) << "Владелец"
		<< setw(INDENTATION) << "Номер"
		<< setw(INDENTATION) << "Тип"
		<< setw(INDENTATION) << "Марка"
		<< setw(INDENTATION) << "Объём двигателя"
		<< setw(INDENTATION) << "Мощность"
		<< setw(INDENTATION) << "Последнее ТО"
		<< setw(INDENTATION) << "Пробег"
		<< setw(INDENTATION) << "Кол-во дверей"
		<< setw(INDENTATION) << "Тип топлива" << endl;
	for (int i = 0; i < num_cars; i++) {
		cout << setw(3) << i + num_vehicles
			<< setw(INDENTATION) << cars[i].getVehicleName()
			<< setw(INDENTATION) << cars[i].getVehicleRegNumber()
			<< setw(INDENTATION) << cars[i].getVehicleType()
			<< setw(INDENTATION) << cars[i].getVehicleBrand()
			<< setw(INDENTATION) << cars[i].getVehicleVolume()
			<< setw(INDENTATION) << cars[i].getVehiclePower()
			<< setw(INDENTATION) << cars[i].getVehicleLastTo()
			<< setw(INDENTATION) << cars[i].getVehicleMileage()
			<< setw(INDENTATION) << cars[i].getNumberOfDoors()
			<< setw(INDENTATION) << cars[i].getFuelType()
			<< endl;
	}

	cout << "Записей " << num_motorcycles << "/" << max_num_vehicles << "." << endl;
	cout << setw(3) << "ID"
		<< setw(INDENTATION) << "Владелец"
		<< setw(INDENTATION) << "Номер"
		<< setw(INDENTATION) << "Тип"
		<< setw(INDENTATION) << "Марка"
		<< setw(INDENTATION) << "Объём двигателя"
		<< setw(INDENTATION) << "Мощность"
		<< setw(INDENTATION) << "Последнее ТО"
		<< setw(INDENTATION) << "Пробег"
		<< setw(INDENTATION) << "Тип расположения"
		<< setw(INDENTATION) << "Боковая коляска" << endl;
	for (int i = 0; i < num_motorcycles; i++) {
		cout << setw(3) << i + num_vehicles + num_cars
			<< setw(INDENTATION) << motorcycles[i].getVehicleName()
			<< setw(INDENTATION) << motorcycles[i].getVehicleRegNumber()
			<< setw(INDENTATION) << motorcycles[i].getVehicleType()
			<< setw(INDENTATION) << motorcycles[i].getVehicleBrand()
			<< setw(INDENTATION) << motorcycles[i].getVehicleVolume()
			<< setw(INDENTATION) << motorcycles[i].getVehiclePower()
			<< setw(INDENTATION) << motorcycles[i].getVehicleLastTo()
			<< setw(INDENTATION) << motorcycles[i].getVehicleMileage()
			<< setw(INDENTATION) << motorcycles[i].getHandlebarType()
			<< setw(INDENTATION) << motorcycles[i].getHasSidecarS()
			<< endl;
	}
}
void RegisterVehicles::DisplayById(int id_vehicle){
	if (id_vehicle >= num_vehicles + num_cars + num_motorcycles || id_vehicle < 0) {
		cout << "Выход за допустимые значения. Допустимые значения: [0; " << num_vehicles + num_cars + num_motorcycles - 1 << "]." << endl;
		exit(1);
	}
	else
	{
		cout << setw(3) << "ID"
			<< setw(INDENTATION) << "Владелец"
			<< setw(INDENTATION) << "Номер"
			<< setw(INDENTATION) << "Тип"
			<< setw(INDENTATION) << "Марка"
			<< setw(INDENTATION) << "Объём двигателя"
			<< setw(INDENTATION) << "Мощность"
			<< setw(INDENTATION) << "Последнее ТО"
			<< setw(INDENTATION) << "Пробег";
		if (id_vehicle < num_vehicles) {
			cout << endl << setw(3) << id_vehicle
				<< setw(INDENTATION) << list[id_vehicle].getVehicleName()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleRegNumber()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleType()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleBrand()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleVolume()
				<< setw(INDENTATION) << list[id_vehicle].getVehiclePower()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleLastTo()
				<< setw(INDENTATION) << list[id_vehicle].getVehicleMileage()
				<< endl;
		}
		else if (id_vehicle < num_vehicles + num_cars) {
			cout << setw(INDENTATION) << "Кол-во дверей" << setw(INDENTATION) << "Тип топлива" << endl;
			cout << setw(3) << id_vehicle
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleName()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleRegNumber()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleType()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleBrand()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleVolume()
				<< setw(INDENTATION) << cars[id_vehicle].getVehiclePower()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleLastTo()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleMileage()
				<< setw(INDENTATION) << cars[id_vehicle].getNumberOfDoors()
				<< setw(INDENTATION) << cars[id_vehicle].getFuelType()
				<< endl;
		}
		else if (id_vehicle < num_vehicles + num_cars + num_motorcycles) {
			cout << setw(INDENTATION) << "Тип расположения" << setw(INDENTATION) << "Боковая коляска" << endl;
			cout << setw(3) << id_vehicle
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleName()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleRegNumber()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleType()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleBrand()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleVolume()
				<< setw(INDENTATION) << cars[id_vehicle].getVehiclePower()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleLastTo()
				<< setw(INDENTATION) << cars[id_vehicle].getVehicleMileage()
				<< setw(INDENTATION) << cars[id_vehicle].getNumberOfDoors()
				<< setw(INDENTATION) << cars[id_vehicle].getFuelType()
				<< endl;
		}

	}
}
void RegisterVehicles::DeleteVehicleById(int id_vehicle) {
	if (id_vehicle >= num_vehicles + num_cars + num_motorcycles || id_vehicle < 0) {
		cout << "Выход за допустимые значения. Допустимые значения: [0; " << num_vehicles + num_cars + num_motorcycles - 1 << "]." << endl;
		return;
	}
	else {
		if (id_vehicle < num_vehicles) {
			for (int i = id_vehicle; i < num_vehicles - 1; i++) {
				list[i] = list[i + 1];
			}
			Vehicle v;
			list[num_vehicles] = v;
			num_vehicles--;
		}
		else if (id_vehicle < num_vehicles + num_cars) {
			for (int i = id_vehicle; i < num_cars - 1; i++) {
				cars[i] = cars[i + 1];
			}
			Car v1;
			list[num_cars] = v1;
			num_cars--;
		}
		else if (id_vehicle < num_vehicles + num_cars + num_motorcycles) {
			for (int i = id_vehicle; i < num_motorcycles - 1; i++) {
				motorcycles[i] = motorcycles[i + 1];
			}
			Motorcycle v2;
			list[num_motorcycles] = v2;
			num_motorcycles--;
		}
	}
}
void RegisterVehicles::SetList(Vehicle* v) {
	list = v;
}
Vehicle* RegisterVehicles::GetList() {
	return list;
}
void RegisterVehicles::Task1() {
	bool flag = false;
	for (int i = 0; i < num_vehicles; i++) {
		if (list[i].task_1()) {
			if (!flag) {
				cout << "Номера автомобилей с пробегом свыше 100тыс. КМ" << endl;
				cout << setw(INDENTATION) << "id" << setw(INDENTATION) << "Регистрационный номер" << endl;
			}
			flag = true;
			cout << setw(INDENTATION) << i << setw(INDENTATION) << list[i].getVehicleRegNumber();
		}
	}
	if (!flag) cout << "Автомобилей с пробегом свыше 100тыс. КМ нет." << endl;
}
void RegisterVehicles::Task2() {
	bool flag = false;
	for (int i = 0; i < num_vehicles; i++) {
		if (list[i].task_2()) {
			if (!flag) {
				cout << "Фамилии владельцев, автомобили которых проходили ТО в течение последнего месяца" << endl;
				cout << setw(INDENTATION) << "id" << setw(INDENTATION) << "Фамилия" << endl;
			}
			flag = true;
			cout << setw(INDENTATION) << i << setw(INDENTATION) << list[i].getVehicleName();
		}
	}
	if (!flag) cout << "Автомобилей которые проходили ТО в течение последнего месяца нет." << endl;
}
void RegisterVehicles::SetNumVehicles(int num) {
	num_vehicles = num;
}