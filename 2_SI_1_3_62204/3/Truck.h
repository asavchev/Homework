#pragma once
#include "Vehicle.h"
class Truck :public Vehicle
{
private:
	int size;
public:
	Truck();
	Truck(const char* make, const char* model, const char* color, const int year, const int mileage, const int size);

	void setsize(const int size);

	const int getsize()const;

	void details();
};