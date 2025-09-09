#include "f1garage_eremenko.h"

f1garage_eremenko::f1garage_eremenko()
{
}

void f1garage_eremenko::addCar(const f1eremenko& car)
{
	cars.push_back(car);
}

void f1garage_eremenko::removeCar(size_t index)
{
    if (index >= cars.size()) {
        throw out_of_range("������ ������� �� ������� ������� ������");
    }
    cars.erase(cars.begin() + index);
    wcout << L"������ #" << index + 1 << L" ������� �� ������!\n";
}

void f1garage_eremenko::displayAllCars() const
{
    if (cars.empty()) {
        wcout << L"\n����� ����!\n";
        return;
    }
    wcout << L"\n=== ��� ������ �1 � ������ ===\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        wcout << L"\n������ #" << i + 1;
        cars[i].displayToConsole();
    }
    wcout << L"\n����� �����: " << cars.size() << L"\n";
}

void f1garage_eremenko::readFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        wcout << L"������ �������� ����� ��� ������: " << filename.c_str() << L"\n";
        return;
    }
    clearGarage();
    int count;
    file >> count;
    file.ignore();
    for (int i = 0; i < count; ++i) {
        f1eremenko car;
        car.readFromFile(file);
        cars.push_back(car);  // ��������� ������
    }
    file.close();
    wcout << L"������ ������� ��������� �� �����: " << filename.c_str() << L"\n";
}

void f1garage_eremenko::writeToFile(const string& filename) const
{
    ofstream file(filename);
    if (!file.is_open()) {
        wcout << L"������ �������� ����� ��� ������: " << filename.c_str() << L"\n";
        return;
    }
    file << cars.size() << "\n";
    for (const auto& car : cars) {
        car.writeToFile(file);  // �������� ����� �������
    }
    file.close();
    wcout << L"������ ������� ��������� � ����: " << filename.c_str() << L"\n";
}

void f1garage_eremenko::clearGarage()
{
    cars.clear();  // ������ ������� ������
    wcout << L"����� ������!\n";
}

size_t f1garage_eremenko::getSize() const
{
    return cars.size();
}

