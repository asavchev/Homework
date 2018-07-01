#include "stdafx.h"
#include "Store.h"

Store::Store():diffnum(0)
{
}

Store::Store(const Store & other)
{
	this->diffnum = other.diffnum;
	if (other.diffnum != 0)
	{
		delete[] this->list;
		list = new Product[other.diffnum];
		for (int i = 0; i < diffnum; i++)
		{
			this->list[i] = other.list[i];
		}
	}
}

Store & Store::operator=(const Store & rhs)
{
	this->diffnum = rhs.diffnum;
	if (rhs.diffnum == 0)
	{
		return *this;
    }
	else
	{
		delete[] this->list;
		list = new Product[rhs.diffnum];
		for (int i = 0; i < diffnum; i++)
		{
			this->list[i] = rhs.list[i];
		}
		return *this;
	}
}

Store::~Store()
{
	delete[] list;
}

int Store::Getdiffnum()
{
	return this->diffnum;
}

void Store::AddProduct(Product & product)
{
	int br = 0;
	for (int i = 0; i < diffnum; i++)
	{
		if (list[i] == product)
		{
			list[i].CountPlus();
			br++;
		}
	}
	if (br == 0)
	{
		if (diffnum == 0)
		{
			product.SetSKU(diffnum);
			list = new Product[1];
			list[diffnum] = product;
			diffnum++;
		}
		else
		{
			product.SetSKU(diffnum);
			Product* list2;
			list2 = new Product[diffnum];
			for (int i = 0; i < diffnum; i++)
			{
				list2[i] = list[i];
			}
			delete[] list;
			diffnum++;
			list = new Product[diffnum];
			diffnum--;
			for (int i = 0; i < diffnum; i++)
			{
				list[i] = list2[i];
			}
			delete[] list2;
			list[diffnum] = product;
			diffnum++;
		}
	}
}

void Store::DeleteProduct(int SKU)
{
		if (list[SKU].Getcount() != 0)
		{
			list[SKU].CountMinus();
		}
		if (list[SKU].Getcount() == 0)
		{
			std::cout << "There are no more elements of this kind\n";
		}
}

void Store::ChangeProduct(int SKU,Product& product)
{
	int br;
	br = list[SKU].Getcount();
	list[SKU] = product;
	list[SKU].SetSKU(SKU);
	list[SKU].Setcout(br);
}

void Store::Display()
{
	if (diffnum == 0)
	{
		std::cout << "No items in the store\n";
	}
	for (int i = 0; i < diffnum; i++)
	{
		list[i].print();
	}
}

int Store::Quit()
{
	return 0;
}
