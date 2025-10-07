#include <iostream>
#include "f1garage_eremenko.h"

void displayMenu() {
    wcout << L"\n=== КАРТОТЕКА МАШИН ФОРМУЛЫ 1 ===\n"
        << L"1. Добавить базовую машину\n"
        << L"2. Добавить расширенную машину\n"  // НОВЫЙ ПУНКТ
        << L"3. Показать все машины\n"
        << L"4. Удалить машину\n"
        << L"5. Сохранить в текстовый файл\n"
        << L"6. Загрузить из текстового файла\n"
        << L"7. Сохранить в Boost файл\n"       // НОВЫЙ ПУНКТ
        << L"8. Загрузить из Boost файла\n"     // НОВЫЙ ПУНКТ
        << L"9. Очистить весь гараж\n"
        << L"10. Выход\n"
        << L"Выберите действие: ";
}
int main() {
    locale::global(locale(""));
    wcout.imbue(locale());
    wcin.imbue(locale());

    f1garage_eremenko garage;
    int choice = 0;
    const string filename = "f1_garage.txt";
    const string boost_filename = "f1_garage_boost.dat";

    do {
        displayMenu();
        wcin >> choice;
        switch (choice) {
        case 1:
            garage.addCar(f1eremenko().readFromConsole());
            wcout << L"Базовая машина добавлена в гараж!\n";
            break;
        case 2:
            garage.addExtendedCar();  // Новый метод для расширенной машины
            break;
        case 3:
            garage.displayAllCars();
            break;
        case 4:
            garage.removeCarByUserInput();
            break;
        case 5:
            garage.writeToFile(filename);
            break;
        case 6:
            garage.readFromFile(filename);
            break;
        case 7:
            garage.saveToBoostFile(boost_filename);  // Boost сохранение
            break;
        case 8:
            garage.loadFromBoostFile(boost_filename); // Boost загрузка
            break;
        case 9:
            garage.clearGarage();
            break;
        case 10:
            wcout << L"Выход из программы...\n";
            break;
        default:
            wcout << L"Неверный выбор! Попробуйте снова.\n";
            break;
        }

        wcin.clear();
        wcin.ignore(10000, L'\n');
    } while (choice != 10);

    return 0;
}