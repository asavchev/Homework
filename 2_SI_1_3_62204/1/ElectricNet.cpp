#include "stdafx.h"
#include "ElectricNet.h"

ElectricNet::ElectricNet() :devices(nullptr), size(0), currentpower(0), maxpower(0)
{
}

ElectricNet::ElectricNet(const int maxpower)
{
	devices = nullptr;
	setcurrentpower(0);
	size = 0;
	setmaxpower(maxpower);
}

ElectricNet::ElectricNet(const ElectricNet & other)
{
	this->size = other.getsize();
	this->currentpower = other.getcurrentpower();
	this->maxpower = other.getmaxpower();
	if (this->size == 0)
	{
		this->devices = nullptr;
	}
	else
	{
		devices = new ElectricDevice[size];
		for (int i = 0; i < this->size; i++)
		{
			this->devices[i] = other.devices[i];
		}
	}
}

ElectricNet & ElectricNet::operator=(const ElectricNet & rhs)
{
	{
		this->size = rhs.getsize();
		this->currentpower = rhs.getcurrentpower();
		this->maxpower = rhs.getmaxpower();
		if (this->size == 0)
		{
			this->devices = nullptr;
		}
		else
		{
			devices = new ElectricDevice[size];
			for (int i = 0; i < this->size; i++)
			{
				this->devices[i] = rhs.devices[i];
			}
		}
	}
	return *this;
}

ElectricNet::~ElectricNet()
{
	delete[] devices;
}

void ElectricNet::operator+=(const ElectricDevice & rhs)
{
	int newpower = 0, i = 0;
	newpower =( currentpower + rhs.getpower());
	if (newpower <= maxpower)
	{
		if (size == 0)
		{
			size++;
			devices = new ElectricDevice[size];
			devices[0] = rhs;
			setcurrentpower(newpower);
		}
		else
		{
			ElectricDevice* ddevice = new ElectricDevice[size];
			for (i = 0; i < size; i++)
			{
				ddevice[i] = devices[i];
			}
			delete[] devices;
			size++;
			devices = new ElectricDevice[size];
			size--;
			for (i = 0; i < size; i++)
			{
				devices[i] = ddevice[i];
			}
			delete[] ddevice;
			devices[size] = rhs;
			size++;
			setcurrentpower(newpower);
		}
	}
}

ElectricNet ElectricNet::operator+(const ElectricDevice & rhs)
{
	int newpower = 0, i = 0;
	newpower = (currentpower + rhs.getpower());
	if (newpower <= maxpower)
	{
		if (size == 0)
		{
			size++;
			devices = new ElectricDevice[size];
			devices[0] = rhs;
			setcurrentpower(newpower);
		}
		else
		{
			ElectricDevice* ddevice = new ElectricDevice[size];
			for (i = 0; i < size; i++)
			{
				ddevice[i] = devices[i];
			}
			delete[] devices;
			size++;
			devices = new ElectricDevice[size];
			size--;
			for (i = 0; i < size; i++)
			{
				devices[i] = ddevice[i];
			}
			delete[] ddevice;
			devices[size] = rhs;
			size++;
			setcurrentpower(newpower);
		}
	}
	return *this;
}

void ElectricNet::operator-=(const ElectricDevice & rhs)
{
	int i,j,k; 
	ElectricDevice * newdev;
	for (i = 0; i < size; i++)
	{
		if (strcmp(devices[i].getname(),rhs.getname())==0)
		{
			size--;
			currentpower -= devices[i].getpower();
			newdev = new ElectricDevice[size];
			for (j = 0; j < i; j++)
			{
				newdev[j] = devices[j];
			}
			for (j = i; j < size; j++)
			{
				k=j+1;
				newdev[j] = devices[k];
			}
			delete[] devices;
			devices = new ElectricDevice[size];
			for (j = 0; j < size; j++)
			{
				devices[j] = newdev[j];
			}
			delete[] newdev;
			break;
		}
	}
}

ElectricNet ElectricNet::operator-(const ElectricDevice & rhs)
{
	int i, j, k;
	ElectricDevice * newdev;
	for (i = 0; i < size; i++)
	{
		if (strcmp(devices[i].getname(), rhs.getname()) == 0)
		{
			size--;
			currentpower -= devices[i].getpower();
			newdev = new ElectricDevice[size];
			for (j = 0; j < i; j++)
			{
				newdev[j] = devices[j];
			}
			for (j = i; j < size; j++)
			{
				k = j + 1;
				newdev[j] = devices[k];
			}
			delete[] devices;
			devices = new ElectricDevice[size];
			for (j = 0; j < size; j++)
			{
				devices[j] = newdev[j];
			}
			delete[] newdev;
			break;
		}
	}
	return *this;
}

ElectricNet ElectricNet::operator[](const char * rhs)
{
	int i,newp,newpp;
	for (i = 0; i < size; i++)
	{
		if (strcmp(devices[i].getname(), rhs) == 0)
		{
			std::cout << "Enter new power for "<<devices[i].getname()<<": ";
			std::cin >> newp;
			newpp = currentpower + newp-devices[i].getpower();
			if (newpp <= maxpower)
			{
				devices[i].setpower(newp);
				currentpower = newpp;
			}
			else
			{
				std::cout << "That change is not possible. Not enought maxpower!\n";
			}
			break;
		}
	}
	print();
	return *this;
}

bool ElectricNet::operator!()
{
	if (getsize() == 0)
		return 1;
	else
		return 0;
}

void ElectricNet::operator++()
{
	setmaxpower(2 * maxpower);
}

void ElectricNet::operator--()
{
	if ((maxpower / 2) > currentpower)
		setmaxpower(maxpower / 2);
}

void ElectricNet::setsize(const int size)
{
	this->size = size;
}

void ElectricNet::setcurrentpower(const int currentpower)
{
	this->currentpower = currentpower;
}

void ElectricNet::setmaxpower(const int maxpower)
{
	this->maxpower = maxpower;
}

const int ElectricNet::getsize() const
{
	return this->size;
}

const int ElectricNet::getcurrentpower() const
{
	return this->currentpower;
}

const int ElectricNet::getmaxpower() const
{
	return this->maxpower;
}

void ElectricNet::print()
{
	if (size == 0)
	{
		std::cout << "No devices\n";
	}
	else
	{
		std::cout << "All devices:\n";
		for (int i = 0; i < size; i++)
		{
			devices[i].print();
		}
		std::cout << "Current power: " << getcurrentpower() << " Max power: " << getmaxpower() << "\n";
	}
}
