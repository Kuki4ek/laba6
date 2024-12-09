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
        cout << "Меню\nВыберите операцию:\n1-Ввод данных с клавиатуры\n2-Ввод в файл\n3-Вывод из файла\n4-Вывод данных на экран\n5-Выполнить задания\n6-Добавить автомобиль\n7-Удаление записи по id\n8-Выход" << endl;
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
            cout << "Введите данные для автомобиля:\n";
            cout << "Владелец: ";
            getline(cin, buff);
            buff_vehicle.setVehicleName(buff);
            cout << "Регистрационный номер: ";
            getline(cin, buff);
            buff_vehicle.setVehicleRegNumber(buff);
            cout << "Тип: ";
            getline(cin, buff);
            buff_vehicle.setVehicleType(buff);
            cout << "Марка: ";
            getline(cin, buff);
            buff_vehicle.setVehicleBrand(buff);
            cout << "Объем (л): ";
            getline(cin, buff);
            buff_vehicle.setVehicleVolume(stof(buff));
            cout << "Мощность (л.с.): ";
            getline(cin, buff);
            buff_vehicle.setVehiclePower(stof(buff));
            cout << "Дата последнего техосмотра: ";
            getline(cin, buff);
            buff_vehicle.setVehicleLastTo(buff);
            cout << "Пробег (км): ";
            getline(cin, buff);
            buff_vehicle.setVehicleMileage(stof(buff));
            if (Vehicles.AddVehicle(buff_vehicle)) {
                cout << "Данные автомобиля успешно сохранены!\n\n";
            }
            else{
                cout << "Лимит данных превышен" << endl;
            }
            break;
        case 7:
            cout << "Введите id записи, которую вы хотите удалить: " << endl;
            int id;
            cin >> id;
            cin.ignore();
            Vehicles.DeleteVehicleById(id);
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Ошибка" << endl;
            break;
        }
    }
    return 0;
}
