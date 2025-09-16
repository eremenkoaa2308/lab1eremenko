#pragma once
#include "f1eremenko.h"
#include <vector>
#include <fstream>
class f1garage_eremenko
{
private:
	vector<f1eremenko> cars;
public:
	f1garage_eremenko();
	~f1garage_eremenko();
	void addCar(const f1eremenko& car);
	void removeCar(size_t index);
	void displayAllCars() const;
	void readFromFile(const string& filename);
	void writeToFile(const string& filename) const;
	void clearGarage();
	void removeCarByUserInput();
	size_t getSize() const;
};

