#pragma once
#include "Account.h"
class CurrentAccount :public Account
{
public:
	CurrentAccount();
	CurrentAccount(const char* iban, const unsigned int ownerid, const int amount);
	CurrentAccount* clone();

	void deposit(const int deposit);
	bool withdraw(const int withdraw);
	void display();
};
