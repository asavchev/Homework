#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle():make(nullptr),model(nullptr),color(nullptr),year(0),mileage(0)
{
}

Vehicle::Vehicle(const char * make, const char * model, const char * color, const int year, const int mileage)
{
	this->make = nullptr;
	this->model = nullptr;
	this->color = nullptr;
	setmake(make);
	setmodel(model);
	setcolor(color);
	setyear(year);
	setmileage(mileage);
}

Vehicle::Vehicle(const Vehicle & other)
{
	this->make = nullptr;
	this->model = nullptr;
	this->color = nullptr;
	setmake(other.getmake());
	setmodel(other.getmodel());
	setcolor(other.getcolor());
	setyear(other.getyear());
	setmileage(other.getmileage());
}

Vehicle & Vehicle::operator=(const Vehicle & rhs)
{
	this->make = nullptr;
	this->model = nullptr;
	this->color = nullptr;
	setmake(rhs.getmake());
	setmodel(rhs.getmodel());
	setcolor(rhs.getcolor());
	setyear(rhs.getyear());
	setmileage(rhs.getmileage());
	return *this;
}

Vehicle::~Vehicle()
{
	delete[] make;
	delete[] model;
	delete[] color;
}

void Vehicle::setmake(const char * make)
{
	if (make == nullptr)
	{
		this->make = nullptr;
	}
	else
	{
		int size = strlen(make) + 1;
		delete[] this->make;
		this->make = new char[size];
		strcpy(this->make, make);
	}
}

void Vehicle::setmodel(const char * model)
{
	if (model == nullptr)
	{
		this->model = nullptr;
	}
	else
	{
		int size = strlen(model) + 1;
		delete[] this->model;
		this->model = new char[size];
		strcpy(this->model, model);
	}
}

void Vehicle::setcolor(const char * color)
{
	if (color == nullptr)
	{
		this->color = nullptr;
	}
	else
	{
		int size = strlen(color) + 1;
		delete[] this->color;
		this->color = new char[size];
		strcpy(this->color, color);
	}
}

void Vehicle::setyear(const int year)
{
	this->year = year;
}

void Vehicle::setmileage(const int mileage)
{
	this->mileage = mileage;
}

const char * Vehicle::getmake() const
{
	return this->make;
}

const char * Vehicle::getmodel() const
{
	return this->model;
}

const char * Vehicle::getcolor() const
{
	return this->color;
}

const int Vehicle::getyear() const
{
	return this->year;
}

const int Vehicle::getmileage() const
{
	return this->mileage;
}

void Vehicle::details()
{
}
