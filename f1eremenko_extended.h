#pragma once
#include "f1eremenko.h"
#include <vector>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
class f1eremenko_extended : public f1eremenko
{
private:
	wstring teamPrincipal;  // Руководитель команды
	double budget;          // Бюджет команды (в млн)
	vector<wstring> sponsors; // Список спонсоров

	friend class boost::serialization::access;

    // Метод сериализации
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        // Сериализуем базовый класс
        ar& boost::serialization::base_object<f1eremenko>(*this);

        // Сериализуем дополнительные поля
        std::string temp_principal(teamPrincipal.begin(), teamPrincipal.end());
        ar& temp_principal;
        teamPrincipal = wstring(temp_principal.begin(), temp_principal.end());

        ar& budget;

        // Сериализуем вектор спонсоров
        std::vector<std::string> temp_sponsors;
        if (Archive::is_loading::value) {
            // При загрузке
            ar& temp_sponsors;
            sponsors.clear();
            for (const auto& sponsor : temp_sponsors) {
                sponsors.push_back(wstring(sponsor.begin(), sponsor.end()));
            }
        }
        else {
            // При сохранении
            for (const auto& sponsor : sponsors) {
                temp_sponsors.push_back(std::string(sponsor.begin(), sponsor.end()));
            }
            ar& temp_sponsors;
        }
    }

public:
    f1eremenko_extended();
    f1eremenko_extended(wstring Team, wstring Driver, int Year, int Power, double Weight, wstring TeamPrincipal, double Budget, vector<wstring> Sponsors = vector<wstring>());
    //переопределение виртуальных методов
    f1eremenko& readFromConsole() override;
    void displayToConsole() const override;
    void readFromFile(std::ifstream& file) override;
    void writeToFile(std::ofstream& file) const override;

    void addSponsor(const wstring& sponsor);
    void displaySponsors() const;

    wstring getTeamPrincipal() const;
    double getBudget() const;
    vector<wstring> getSponsors() const;
};

