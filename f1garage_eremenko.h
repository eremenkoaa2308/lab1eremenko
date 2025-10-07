#pragma once
#include "f1eremenko.h"
#include "f1eremenko_extended.h"
#include <vector>
#include <fstream>
#include <memory>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
class f1garage_eremenko
{
private:
	// �������� �� ����� ��������� ��� ������������
	vector<shared_ptr<f1eremenko>> cars;
public:
	f1garage_eremenko();
	~f1garage_eremenko();
	// ��������� ������������� ������ ��� ������ �����
	void addCar(const f1eremenko& car);
	void addCar(const f1eremenko_extended& car);
	void addCar(shared_ptr<f1eremenko> car);

	void removeCar(size_t index);
	void displayAllCars() const;

	// ����� ������ ��� Boost ������������
	void saveToBoostFile(const string& filename) const;
	void loadFromBoostFile(const string& filename);

	void readFromFile(const string& filename);
	void writeToFile(const string& filename) const;

	void clearGarage();
	void removeCarByUserInput();
	size_t getSize() const;

	// ����� ����� ��� ���������� ����������� ������
	void addExtendedCar();
};

