#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class f1eremenko
{
private:
	wstring team;
	wstring driver;
	int year;
	int power;
	double weight;

	static int readIntWithValidation(const wstring& prompt, int min, int max);
	static double readDoubleWithValidation(const wstring& prompt, double min, double max);
	static wstring readStringWithValidation(const wstring& prompt);
public:
	f1eremenko();
	f1eremenko(wstring Team, wstring Driver, int Year, int Power, double Weight);
	void readFromConsole();
	void displayToConsole() const;
	void readFromFile(ifstream& file);
	void writeToFile(ofstream& file) const;
	wstring getTeam() const;
	wstring getDriver() const;
	int getYear() const;
	int getPower() const;
	double getWeight() const;


};

