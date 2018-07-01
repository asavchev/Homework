#include "stdafx.h"
#include "Truck.h"

Truck::Truck():Vehicle(),size(0)
{
}

Truck::Truck(const char * make, const char * model, const char * color, const int year, const int mileage, const int size):Vehicle(make,model,color,year,mileage)
{
	setsize(size);
}

void Truck::setsize(const int size)
{
	this->size = size;
}

const int Truck::getsize() const
{
	return this->size;
}

void Truck::details()
{
	std::cout << "Truck details:\n";
	std::cout << "Make: " << getmake() << " Modle: " << getmodel() << " Color: " << getcolor() << " Year: " << getyear() << " Mileage: " << getmileage() <<" Size:  "<<getsize()<<"\n";
}
