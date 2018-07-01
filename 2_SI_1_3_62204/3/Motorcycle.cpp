#include "stdafx.h"
#include "Motorcycle.h"

Motorcycle::Motorcycle():Vehicle(),type(nullptr)
{
}

Motorcycle::Motorcycle(const char * make, const char * model, const char * color, const int year, const int mileage, const char * type):Vehicle(make,model,color,year,mileage)
{
	this->type = nullptr;
	settype(type);
}

Motorcycle::Motorcycle(const Motorcycle & other):Vehicle(other)
{
	this->type = nullptr;
	settype(other.gettype());
}

Motorcycle & Motorcycle::operator=(const Motorcycle & rhs)
{
	Vehicle::operator= (rhs);
	this->type = nullptr;
	settype(rhs.gettype());
	return *this;
}

Motorcycle::~Motorcycle()
{
	delete[] type;
}

void Motorcycle::settype(const char * type)
{
	if (type == nullptr)
	{
		this->type = nullptr;
	}
	else
	{
		int size = strlen(type) + 1;
		delete[] this->type;
		this->type = new char[size];
		strcpy(this->type, type);
	}
}

const char * Motorcycle::gettype() const
{
	return this->type;
}

void Motorcycle::details()
{
	std::cout << "Motorcycle details:\n";
	std::cout << "Make: " << getmake() << " Modle: " << getmodel() << " Color: " << getcolor() << " Year: " << getyear() << " Mileage: " << getmileage() << " Type:  " << gettype() << "\n";
}
