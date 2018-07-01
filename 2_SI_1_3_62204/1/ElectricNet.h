#pragma once
#include "ElectrcDevice.h"
class ElectricNet
{
private:
	ElectricDevice * devices;
	int size=0;
	int currentpower;
	int maxpower;
public:
	ElectricNet();
	ElectricNet(const int maxpower);
	ElectricNet(const ElectricNet& other);
	ElectricNet& operator=(const ElectricNet& rhs);
	~ElectricNet();

	void operator+=(const ElectricDevice& rhs);
	ElectricNet operator+(const ElectricDevice& rhs);
	void operator-=(const ElectricDevice& rhs);
	ElectricNet operator-(const ElectricDevice& rhs);
	ElectricNet operator[](const char* rhs);
	bool operator!();
	void operator++();
	void operator--();

	void setsize(const int size);
	void setcurrentpower(const int currentpower);
	void setmaxpower(const int power);

	const int getsize()const;
	const int getcurrentpower()const;
	const int getmaxpower()const;

	void print();
};
