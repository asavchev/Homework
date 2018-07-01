#include "stdafx.h"
#include <cstring>
#include "ElectrcDevice.h"

ElectricDevice::ElectricDevice() :name(nullptr), power(0)
{
}

ElectricDevice::ElectricDevice(const char * name, const int power)
{
	this->name = nullptr;
	setname(name);
	setpower(power);
}

ElectricDevice::ElectricDevice(const ElectricDevice & other)
{
	this->name = nullptr;
	setname(other.getname());
	setpower(other.getpower());
}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice & rhs)
{
	this->name = nullptr;
	setname(rhs.getname());
	setpower(rhs.getpower());
	return *this;
}

ElectricDevice::~ElectricDevice()
{
	delete[] name;
}

void ElectricDevice::setname(const char * name)
{
	delete[] this->name;
	if (name == nullptr)
	{
		this->name = nullptr;
	}
	else
	{
		int size = 0;
		size = strlen(name);
		size++;
		this->name = new char[size];
		strcpy(this->name, name);
	}
}

void ElectricDevice::setpower(const int power)
{
	this->power = power;
}

const char * ElectricDevice::getname() const
{
	return this->name;
}

const int ElectricDevice::getpower() const
{
	return this->power;
}


void ElectricDevice::print()
{
	std::cout << "Name: " << getname() << " Power: " << getpower() << "\n";
}