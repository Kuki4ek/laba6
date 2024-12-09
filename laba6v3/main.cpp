#define _CRT_SECURE_NO_WARNINGS
#include "Libs/vechicle.h"
#include "Libs/file_proccessor.h"
#include "Libs/parser.h"
#include "Libs/register_vehicles.h"
#include "Libs/other_functions.h"
#include <iostream>
#include <string>
#include <locale>
#define FILENAME "vehicles.txt"
#define MAX_VEHICLE_COUNT 32

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    RegisterVehicles Vehicles(MAX_VEHICLE_COUNT);
    Vehicle buff_vehicle;
    while (true) {
        int operation = 0;
        cout << "����\n�������� ��������:\n1-���� ������ � ����������\n2-���� � ����\n3-����� �� �����\n4-����� ������ �� �����\n5-��������� �������\n6-�������� ����������\n7-�������� ������ �� id\n8-�����" << endl;
        cout << ">";
        cin >> operation;
        int count = 0;
        string buff;
        switch (operation)
        {
        case 1:
            Vehicles.SetList(UserInput(&count, MAX_VEHICLE_COUNT));
            Vehicles.SetNumVehicles(count);
            break;
        case 2:
            Vehicles.WriteToFile();
            break;
        case 3:
            Vehicles.ReadFromFile();
            break;
        case 4:
            Vehicles.DisplayAll();
            break;
        case 5:
            Vehicles.Task1();
            Vehicles.Task2();
            break;
        case 6:
            cin.ignore();
            cout << "������� ������ ��� ����������:\n";
            cout << "��������: ";
            getline(cin, buff);
            buff_vehicle.setVehicleName(buff);
            cout << "��������������� �����: ";
            getline(cin, buff);
            buff_vehicle.setVehicleRegNumber(buff);
            cout << "���: ";
            getline(cin, buff);
            buff_vehicle.setVehicleType(buff);
            cout << "�����: ";
            getline(cin, buff);
            buff_vehicle.setVehicleBrand(buff);
            cout << "����� (�): ";
            getline(cin, buff);
            buff_vehicle.setVehicleVolume(stof(buff));
            cout << "�������� (�.�.): ";
            getline(cin, buff);
            buff_vehicle.setVehiclePower(stof(buff));
            cout << "���� ���������� ����������: ";
            getline(cin, buff);
            buff_vehicle.setVehicleLastTo(buff);
            cout << "������ (��): ";
            getline(cin, buff);
            buff_vehicle.setVehicleMileage(stof(buff));
            if (Vehicles.AddVehicle(buff_vehicle)) {
                cout << "������ ���������� ������� ���������!\n\n";
            }
            else{
                cout << "����� ������ ��������" << endl;
            }
            break;
        case 7:
            cout << "������� id ������, ������� �� ������ �������: " << endl;
            int id;
            cin >> id;
            cin.ignore();
            Vehicles.DeleteVehicleById(id);
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "������" << endl;
            break;
        }
    }
    return 0;
}
