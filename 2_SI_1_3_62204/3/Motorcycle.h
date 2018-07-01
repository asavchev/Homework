#pragma once
#include "Vehicle.h"
class Motorcycle :public Vehicle
{
private:
	char* type;
public:
	Motorcycle();
	Motorcycle(const char* make, const char* model, const char* color, const int year, const int mileage, const char* type);
	Motorcycle(const Motorcycle& other);
	Motorcycle& operator=(const Motorcycle& rhs);
	~Motorcycle();

	void settype(const char* type);

	const char* gettype()const;

	void details();
};