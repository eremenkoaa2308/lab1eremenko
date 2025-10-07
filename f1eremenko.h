#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
using namespace std;
class f1eremenko
{
protected:
	wstring team;
	wstring driver;
	int year;
	int power;
	double weight;
	// Дружественный класс для сериализации
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		std::string temp_team(team.begin(), team.end());
		std::string temp_driver(driver.begin(), driver.end());

		ar& temp_team& temp_driver& year& power& weight;

		team = wstring(temp_team.begin(), temp_team.end());
		driver = wstring(temp_driver.begin(), temp_driver.end());
	}
public:
	virtual ~f1eremenko() = default;
	f1eremenko();
	f1eremenko(wstring Team, wstring Driver, int Year, int Power, double Weight);
	virtual f1eremenko& readFromConsole();
	virtual void displayToConsole() const;
	virtual void readFromFile(ifstream& file);
	virtual void writeToFile(ofstream& file) const;

	wstring getTeam() const;
	wstring getDriver() const;
	int getYear() const;
	int getPower() const;
	double getWeight() const;

	static int readIntWithValidation(const wstring& prompt, int min, int max);
	static double readDoubleWithValidation(const wstring& prompt, double min, double max);
	static wstring readStringWithValidation(const wstring& prompt);

};

