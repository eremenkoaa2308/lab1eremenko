#include "f1eremenko_extended.h"
#include <boost/serialization/export.hpp>

f1eremenko_extended::f1eremenko_extended(): f1eremenko(), teamPrincipal(L"Christian Horner"), budget(500.0)
{
    sponsors = { L"Red Bull", L"Tag Heuer", L"Puma" };
}

f1eremenko_extended::f1eremenko_extended(wstring Team, wstring Driver, int Year,
    int Power, double Weight, wstring TeamPrincipal,
    double Budget, vector<wstring> Sponsors)
    : f1eremenko(Team, Driver, Year, Power, Weight),
    teamPrincipal(TeamPrincipal), budget(Budget), sponsors(Sponsors)
{
}

f1eremenko& f1eremenko_extended::readFromConsole()
{
    // �������� ����� �������� ������
    f1eremenko::readFromConsole();

    // ���� �������������� �����
    teamPrincipal = readStringWithValidation(L"������������ �������: ");
    budget = readDoubleWithValidation(L"������ ������� (��� $, 50-1000): ", 50.0, 1000.0);

    // ���� ���������
    sponsors.clear();
    wcout << L"������� ��������� (������ ������ ��� ����������):\n";
    while (true) {
        wcout << L"�������: ";
        wstring sponsor;
        getline(wcin, sponsor);
        //��������� �� ������ ������ ��� ����������
        if (sponsor.empty()) {
            break;
        }

        // ���������, ��� ������ �� ������� ������ �� ��������
        bool isEmpty = true;
        for (wchar_t c : sponsor) {
            if (!iswspace(c)) {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
        sponsors.push_back(sponsor);
    }

    return *this;
}
void f1eremenko_extended::addSponsor(const wstring& sponsor)
{
    sponsors.push_back(sponsor);
}

void f1eremenko_extended::displaySponsors() const
{
    if (!sponsors.empty()) {
        wcout << L"��������: ";
        for (size_t i = 0; i < sponsors.size(); ++i) {
            wcout << sponsors[i];
            if (i < sponsors.size() - 1) wcout << L", ";
        }
        wcout << L"\n";
    }
    else {
        wcout << "� ������� ����������� ��������!";
    }
}

wstring f1eremenko_extended::getTeamPrincipal() const
{
    return teamPrincipal;
}

double f1eremenko_extended::getBudget() const
{
    return budget;
}

vector<wstring> f1eremenko_extended::getSponsors() const
{
    return sponsors;
}

void f1eremenko_extended::displayToConsole() const
{
    // �������� ����� �������� ������
    f1eremenko::displayToConsole();

    // ������� �������������� ����
    wcout << L"������������: " << teamPrincipal << L"\n"
        << L"������: " << budget << L" ��� $\n"
        << L"���������� ���������: " << sponsors.size() << L"\n";

    displaySponsors();
}

void f1eremenko_extended::readFromFile(std::ifstream& file)
{
    // ������ ������� ����
    f1eremenko::readFromFile(file);

    // ������ �������������� ����
    string temp;
    getline(file, temp);
    teamPrincipal = wstring(temp.begin(), temp.end());

    file >> budget;
    file.ignore();

    // ������ ���������
    sponsors.clear();
    int sponsorCount;
    file >> sponsorCount;
    file.ignore();

    for (int i = 0; i < sponsorCount; ++i) {
        getline(file, temp);
        sponsors.push_back(wstring(temp.begin(), temp.end()));
    }
}

void f1eremenko_extended::writeToFile(std::ofstream& file) const
{
    // ���������� ������� ����
    f1eremenko::writeToFile(file);

    // ���������� �������������� ����
    string temp_principal(teamPrincipal.begin(), teamPrincipal.end());
    file << temp_principal << "\n"
        << budget << "\n"
        << sponsors.size() << "\n";

    for (const auto& sponsor : sponsors) {
        string temp_sponsor(sponsor.begin(), sponsor.end());
        file << temp_sponsor << "\n";
    }
}


