#include "stdafx.h"
#include "Account.h"

Account::Account():iban(nullptr)
{
}

Account::Account(const char * iban, const unsigned int ownerid, const int amount)
{
	this->iban = nullptr;
	setiban(iban);
	setownerid(ownerid);
	setamount(amount);
}

Account::Account(const Account & other)
{
	this->iban = nullptr;
	setiban(other.getiban());
	setownerid(other.getownerid());
	setamount(other.getBalance());
}

Account & Account::operator=(const Account & rhs)
{
	if (this != &rhs)
	{
		setiban(rhs.getiban());
		setownerid(rhs.getownerid());
		setamount(rhs.getBalance());
	}
	return *this;
}

Account::~Account()
{
	delete[] iban;
}

Account * Account::clone()
{
	return nullptr;
}


void Account::setiban(const char * iban)
{
	if (iban == nullptr)
	{
		delete[] this->iban;
		this->iban = nullptr;
	}
	else
	{
		int size = strlen(iban) + 1;
		delete[] this->iban;
		this->iban = new char[size];
		strcpy(this->iban, iban);
	}
}

void Account::setownerid(const unsigned int ownerid)
{
	this->ownerid = ownerid;
}

void Account::setamount(const int amount)
{
	this->amount = amount;
}

const char * Account::getiban() const
{
	return this->iban;
}

const unsigned int Account::getownerid() const
{
	return this->ownerid;
}

const int Account::getBalance() const
{
	return this->amount;
}


void Account::deposit(const int deposit)
{
	this->amount += deposit;
}

bool Account::withdraw(const int withdraw)
{
	if (withdraw <= amount)
	{
		amount -= withdraw;
		return true;
	}
	std::cout << "Not enough money!\n";
	return false;
}

void Account::display()
{
	std::cout << "iban: " << getiban() << " ownerid: " << getownerid() << " Balance: " << getBalance() << "\n";
}
