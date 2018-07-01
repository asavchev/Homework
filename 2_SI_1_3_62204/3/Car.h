#pragma once
#include "Vehicle.h"
class Car :public Vehicle
{
public:
	Car();
	Car(const char* make, const char* model, const char* color, const int year, const int mileage);
	
	void details();
};
