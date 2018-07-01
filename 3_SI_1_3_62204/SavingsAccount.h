#pragma once
#include "Account.h"
class SavingsAccount :public Account
{
private:
	double interestRate;
public:
	SavingsAccount();
	SavingsAccount(const char* iban, const unsigned int ownerid, const int amount,const double interestRate);
	SavingsAccount* clone();

	void setInterestRate(const int rate);
	const double getInterestRate()const;
	void deposit(const int deposit);
	bool withdraw(const int withdraw);
	void display();
};
