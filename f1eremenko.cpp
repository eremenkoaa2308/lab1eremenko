#include "f1eremenko.h"

int f1eremenko::readIntWithValidation(const wstring& prompt, int min, int max)
{
    int value;
    wcout << prompt;
    while (!(wcin >> value) || value < min || value > max) {
        wcin.clear();
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        wcout << L"Ошибка! Введите значение от " << min << L" до " << max << L": ";
    }
    wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
    return value;
}

double f1eremenko::readDoubleWithValidation(const wstring& prompt, double min, double max)
{
    double value;
    wcout << prompt;
    while (!(wcin >> value) || value < min || value > max) {
        wcin.clear();
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        wcout << L"Ошибка! Введите значение от " << min << L" до " << max << L": ";
    }
    wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
    return value;
}

wstring f1eremenko::readStringWithValidation(const wstring& prompt)
{
    wstring value;
    wcout << prompt;
    while (getline(wcin, value).fail() || value.empty()) {
        wcin.clear();
        wcout << L"Ошибка! Введите корректное значение: ";
    }
    return value;
}

f1eremenko::f1eremenko()
{
	team = L"Red Bull";
	driver = L"Max Verstappen";
	year = 2025;
	power = 900;
	weight = 798;
}

f1eremenko::f1eremenko(wstring Team, wstring Driver, int Year, int Power, double Weight)
{
	team = Team;
	driver = Driver;
	year = Year;
	power = Power;
	weight = Weight;
}

f1eremenko& f1eremenko::readFromConsole()
{
    wcout << L"\n===Ввод данных машины Формулы1 ===\n";
    wcin.ignore();
    team = readStringWithValidation(L"Команда: ");
    driver = readStringWithValidation(L"Пилот: ");
    year = readIntWithValidation(L"Год (1950-2030): ", 1950, 2030);
    power = readIntWithValidation(L"Мощность (л.с., 500-2000): ", 500, 2000);
    weight = readDoubleWithValidation(L"Вес (кг, 500-1000): ", 500.0, 1000.0);
    return *this;
}

void f1eremenko::displayToConsole() const
{
    wcout << L"\n=== Данные машины Ф1 ===\n"
        << L"Команда: " << getTeam() << L"\n"
        << L"Пилот: " << getDriver() << L"\n"
        << L"Год: " << getYear() << L"\n"
        << L"Мощность: " << getPower() << L" л.с.\n"
        << L"Вес: " << getWeight() << L" кг\n";
}

void f1eremenko::readFromFile(ifstream& file)
{
    string temp;
    getline(file, temp);
    team = wstring(temp.begin(), temp.end());
    getline(file, temp);
    driver = wstring(temp.begin(), temp.end());
    file >> year;
    file >> power;
    file >> weight;
    file.ignore();
}

void f1eremenko::writeToFile(ofstream& file) const
{
    string team_str(team.begin(), team.end());
    string driver_str(driver.begin(), driver.end());
    file << team_str << "\n"
        << driver_str << "\n"
        << year << "\n"
        << power << "\n"
        << weight << "\n";
}

wstring f1eremenko::getTeam() const
{
    return team;
}

wstring f1eremenko::getDriver() const
{
    return driver;
}

int f1eremenko::getYear() const
{
    return year;
}


int f1eremenko::getPower() const
{
    return power;
}

double f1eremenko::getWeight() const
{
    return weight;
}
