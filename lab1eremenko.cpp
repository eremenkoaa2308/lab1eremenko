#include <iostream>
#include "f1garage_eremenko.h"

void displayMenu() {
    wcout << L"\n=== КАРТОТЕКА МАШИН ФОРМУЛЫ 1 ===\n"
        << L"1. Добавить машину\n"
        << L"2. Показать все машины\n"
        << L"3. Удалить машину\n"  // Новый пункт меню
        << L"4. Сохранить в файл\n"
        << L"5. Загрузить из файла\n"
        << L"6. Очистить весь гараж\n"
        << L"7. Выход\n"
        << L"Выберите действие: ";
}
int main() {
    locale::global(locale(""));
    wcout.imbue(locale());
    wcin.imbue(locale());
    f1garage_eremenko garage;
    int choice = 0;
    const string filename = "f1_garage.txt";
    do {
        displayMenu();
        wcin >> choice;
        switch (choice) {
        case 1: {
            f1eremenko newCar;
            newCar.readFromConsole();
            garage.addCar(newCar);
            wcout << L"Машина добавлена в гараж!\n";
            break;
        }
        case 2:
            garage.displayAllCars();
            break;
        case 3: {  // Удаление одной машины
            if (garage.getSize() == 0) {
                wcout << L"Гараж пуст! Нечего удалять.\n";
                break;
            }
            garage.displayAllCars();
            wcout << L"Введите номер машины для удаления (1-" << garage.getSize() << L"): ";
            size_t index;
            wcin >> index;
            if (index < 1 || index > garage.getSize()) {
                wcout << L"Неверный номер машины!\n";
            }
            else {
                try {
                    garage.removeCar(index - 1);  // -1 потому что пользователь видит с 1
                }
                catch (const exception& e) {
                    wcout << L"Ошибка при удалении: " << e.what() << L"\n";
                }
            }
            break;
        }
        case 4:
            garage.writeToFile(filename);
            break;
        case 5:
            garage.readFromFile(filename);
            break;
        case 6:
            garage.clearGarage();
            break;
        case 7:
            wcout << L"Выход из программы...\n";
            break;
        default:
            wcout << L"Неверный выбор! Попробуйте снова.\n";
            break;
        }
        // Очистка буфера ввода
        wcin.clear();
        wcin.ignore(10000, L'\n');
    } while (choice != 7);
    return 0;
}

