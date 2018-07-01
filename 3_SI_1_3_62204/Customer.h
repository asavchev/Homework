#pragma once
#include <iostream>
#include <cstring>
class Customer
{
private:
	unsigned int id;
	char* name;
	char* address;
public:
	Customer();
	Customer(const unsigned int id,const char* name,const char * address);
	Customer(const Customer& other);
	Customer& operator=(const Customer& rhs);
	~Customer();

	void setid(const unsigned int id);
	void setname(const char* name);
	void setaddress(const char* address);

	const unsigned int getid()const;
	const char* getname()const;
	const char* getaddress()const;

	void display();
};
