#pragma once
#include "Product.h"
class Store
{
private:
	Product* list;
	int diffnum;
public:
	Store();
	Store(const Store& other);
	Store& operator=(const Store& rhs);
	~Store();

	int Getdiffnum();

	void AddProduct(Product& product);
	void DeleteProduct(int SKU);
	void ChangeProduct(int SKU,Product& procduct);
	void Display();
	int Quit();
};
