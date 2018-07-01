#pragma once
#include <iostream>
#include <cstring>
class Vehicle
{
private:
	char* make;
	char* model;
	char* color;
	int year;
	int mileage;
public:
	Vehicle();
	Vehicle(const char* make, const char* model, const char* color, const int year, const int mileage);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& rhs);
	~Vehicle();

	void setmake(const char* make);
	void setmodel(const char* model);
	void setcolor(const char* color);
	void setyear(const int year);
	void setmileage(const int mileage);

	const char* getmake()const;
	const char* getmodel()const;
	const char* getcolor()const;
	const int getyear()const;
	const int getmileage()const;

	virtual void details();
};