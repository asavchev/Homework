#include "stdafx.h"
#include "Product.h"

Product::Product():SKU(0),brand("Error"),model("Error"),price(0),count(0)
{
}

Product::Product(const char * brand,const char * model, double price)
{
	this->SKU = 0;
	Setbrand(brand);
	Setmodel(model);
	Setprice(price);
	this->count = 1;
}

Product::Product(const Product & product)
{
	this->SKU = product.SKU;
	strcpy(this->brand, product.brand);
	strcpy(this->model, product.model);
	this->price = product.price;
	this->count = product.count;
}

void Product::Setbrand(const char * brand)
{
	strcpy(this->brand, brand);
}

void Product::Setmodel(const char * model)
{
	strcpy(this->model, model);
}

void Product::Setprice(const double price)
{
	this->price = price;
}

void Product::SetSKU(const int SKU)
{
	this->SKU = SKU;
}

void Product::Setcout(const int cout)
{
	this->count = count;
}

void Product::CountPlus()
{
	this->count++;
}

void Product::CountMinus()
{
	this->count--;
}

bool Product::operator==(const Product & rhs)
{
	int br = 0,i;
	for (i = 0; i < 64; i++)
	{
		if (this->brand[i] == '\0'&&rhs.brand[i] == '\0')
		{
			br++;
			break;
		}
		if (this->brand[i] != rhs.brand[i])
		{
			break;
		}
	}
	for (i = 0; i < 64; i++)
	{
		if (this->model[i] == '\0'&&rhs.model[i] == '\0')
		{
			br++;
			break;
		}
		if (this->model[i] != rhs.model[i])
		{
			break;
		}
	}
	if (this->price == rhs.price)
	{
		br++;
	}
	if (br == 3)
	{
		return true;
	}
	else return false;
}

int Product::GetSKU()
{
	return this->SKU;
}

double Product::Getprice()
{
	return this->price;
}

int Product::Getcount()
{
	return this->count;
}

char Product::Getmodel()
{
	return this->model[64];
}

char Product::Getbrand()
{
	return this->brand[64];
}

void Product::print()
{
	std::cout << "SKU - " <<GetSKU();
	std::cout << "  Brand - " << this->brand;
	std::cout << "  Model - " << this->model;
	std::cout << "  Price - " << Getprice();
	std::cout << "  Count - " << Getcount() << '\n';

}
