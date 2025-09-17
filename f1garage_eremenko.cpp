#include "f1garage_eremenko.h"

f1garage_eremenko::f1garage_eremenko()
{
}

f1garage_eremenko::~f1garage_eremenko()
{
    clearGarage();
}

void f1garage_eremenko::addCar(const f1eremenko& car)
{
	cars.push_back(car);
}

void f1garage_eremenko::removeCar(size_t index)
{
    if (index >= cars.size()) {
        throw out_of_range("Индекс выходит за пределы размера гаража");
    }
    cars.erase(cars.begin() + index);
    wcout << L"Машина #" << index + 1 << L" удалена из гаража!\n";
}

void f1garage_eremenko::displayAllCars() const
{
    if (cars.empty()) {
        wcout << L"\nГараж пуст!\n";
        return;
    }
    wcout << L"\n=== ВСЕ МАШИНЫ Ф1 В ГАРАЖЕ ===\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        wcout << L"\nМашина #" << i + 1;
        cars[i].displayToConsole();
    }
    wcout << L"\nВсего машин: " << cars.size() << L"\n";
}

void f1garage_eremenko::readFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла для чтения: " << filename.c_str() << L"\n";
        return;
    }
    clearGarage();
    int count;
    file >> count;
    file.ignore();
    for (int i = 0; i < count; ++i) {
        f1eremenko car;
        car.readFromFile(file);
        cars.push_back(car);  // Добавляем объект
    }
    file.close();
    wcout << L"Данные успешно загружены из файла: " << filename.c_str() << L"\n";
}

void f1garage_eremenko::writeToFile(const string& filename) const
{
    ofstream file(filename);
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла для записи: " << filename.c_str() << L"\n";
        return;
    }
    file << cars.size() << "\n";
    for (const auto& car : cars) {
        car.writeToFile(file);  // Вызываем метод объекта
    }
    file.close();
    wcout << L"Данные успешно сохранены в файл: " << filename.c_str() << L"\n";
}

void f1garage_eremenko::clearGarage()
{
    for (auto& car : cars) {
        delete& car; // Удаляем каждый объект
    }
    cars.clear(); // Очищаем вектор
    wcout << L"Гараж очищен!\n";
}

size_t f1garage_eremenko::getSize() const
{
    return cars.size();
}

void f1garage_eremenko::removeCarByUserInput()
{
    if (cars.empty()) {
        wcout << L"Гараж пуст! Нечего удалять.\n";
        return;
    }

    displayAllCars();
    wcout << L"Введите номер машины для удаления (1-" << cars.size() << L"): ";

    size_t index;
    wcin >> index;

    if (index < 1 || index > cars.size()) {
        wcout << L"Неверный номер машины!\n";
        return;
    }

    try {
        removeCar(index - 1);
    }
    catch (const exception& e) {
        wcout << L"Ошибка при удалении: " << e.what() << L"\n";
    }
}