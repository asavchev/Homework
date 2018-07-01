#pragma once
#include<iostream>
class ElectricDevice
{
private:
	char* name;
	int power;
public:
	ElectricDevice();
	ElectricDevice(const char* name, const int power);
	ElectricDevice(const ElectricDevice& other);
	ElectricDevice& operator=(const ElectricDevice& rhs);
	~ElectricDevice();

	void setname(const char* name);
	void setpower(const int power);

	const char* getname()const;
	const int getpower()const;

	void print();
};