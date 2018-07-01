#include "stdafx.h"
#include "Car.h"

Car::Car():Vehicle()
{
}

Car::Car(const char * make, const char * model, const char * color, const int year, const int mileage):Vehicle(make,model,color,year,mileage)
{
}

void Car::details()
{
	std::cout << "Car details:\n";
	std::cout << "Make: " << getmake() << " Modle: " << getmodel() << " Color: " << getcolor() << " Year: " << getyear() << " Mileage: " << getmileage() << "\n";
}
