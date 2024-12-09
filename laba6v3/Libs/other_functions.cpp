#include "other_functions.h"
#include <iostream>
Vehicle* UserInput(int* countIn, int MaxCount) {
    int count = 0;
    cout << "������� ����������� �������" << endl;
    while (true) {
        cin >> count;
        if (count > MaxCount) {
            cout << "������, ���������� �����: ";
        }
        else {
            break;
        }
    }
    *countIn = count;
    cin.ignore();
    Vehicle* v = new Vehicle[count];
    for (int i = 0; i < count; i++) {
        string buff;
        std::cout << "������� ������ ��� ���������� " << (i + 1) << ":\n";
        std::cout << "��������: ";
        getline(std::cin, buff);
        v[i].setVehicleName(buff);
        std::cout << "��������������� �����: ";
        getline(std::cin, buff);
        v[i].setVehicleRegNumber(buff);
        std::cout << "���: ";
        getline(std::cin, buff);
        v[i].setVehicleType(buff);
        std::cout << "�����: ";
        getline(std::cin, buff);
        v[i].setVehicleBrand(buff);
        std::cout << "����� (�): ";
        getline(std::cin, buff);
        v[i].setVehicleVolume(stof(buff));
        std::cout << "�������� (�.�.): ";
        getline(std::cin, buff);
        v[i].setVehiclePower(stof(buff));
        std::cout << "���� ���������� ����������: ";
        getline(std::cin, buff);
        v[i].setVehicleLastTo(buff);
        std::cout << "������ (��): ";
        getline(std::cin, buff);
        v[i].setVehicleMileage(stof(buff));
        std::cout << "������ ���������� " << (i + 1) << " ������� ���������!\n\n";
    }
    return v;
}