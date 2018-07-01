#include "stdafx.h"
#include "Customer.h"

Customer::Customer():id(0),name(nullptr),address(nullptr)
{
}

Customer::Customer(const unsigned int id,const char * name,const char * address)
{
	this->name = nullptr;
	this->address = nullptr;
	setid(id);
	setname(name);
	setaddress(address);
}

Customer::Customer(const Customer & other)
{
	this->name = nullptr;
	this->address = nullptr;
	setid(other.getid());
	setname(other.getname());
	setaddress(other.getaddress());
}

Customer & Customer::operator=(const Customer & rhs)
{
	if (this != &rhs)
	{
		setid(rhs.getid());
		setname(rhs.getname());
		setaddress(rhs.getaddress());
	}
	return *this;
}

Customer::~Customer()
{
	delete[] name;
	delete[] address;
}

void Customer::setid(const unsigned int id)
{
	this->id = id;
}

void Customer::setname(const char * name)
{
	
	if (name == nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	else
	{
		int size = strlen(name) + 1;
		delete[] this->name;
		this->name = new char[size];
		strcpy(this->name, name);
	}
}

void Customer::setaddress(const char * address)
{
	
	if (address == nullptr)
	{
		delete[] this->address;
		this->address = nullptr;
	}
	else
	{
		int size = strlen(address) + 1;
		delete[] this->address;
		this->address = new char[size];
		strcpy(this->address, address);
	}
}

const unsigned int Customer::getid() const
{
	return this->id;
}

const char * Customer::getname() const
{
	return this->name;
}

const char * Customer::getaddress() const
{
	return this->address;
}

void Customer::display()
{
	std::cout << "ID: " << getid() << " Name: " << getname() << " Address: " << getaddress()<<"\n";
}
