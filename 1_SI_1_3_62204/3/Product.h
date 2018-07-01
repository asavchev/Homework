#pragma once
#include <iostream>
#include <cstring>
class Product
{
private:
	int SKU;
	char brand[64];
	char model[64];
	double price;
	int count;
public:
	Product();
	Product(const char* brand,const char* model, double price);
	Product(const Product& product);

	void Setbrand(const char* brand);
	void Setmodel(const char* model);
	void Setprice(const double price);
	void SetSKU(const int SKU);
	void Setcout(const int cout);

	void CountPlus();
	void CountMinus();
	
	bool operator==(const Product& rhs);

	int GetSKU();
	double Getprice();
	int Getcount();
	char Getmodel();
	char Getbrand();
	 
	void print();
};