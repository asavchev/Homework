#include "stdafx.h"
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount():Account(),interestRate(0)
{
}

SavingsAccount::SavingsAccount(const char * iban, const unsigned int ownerid, const int amount,const double interestRate):Account(iban,ownerid,amount)
{
	this->interestRate = interestRate;
}

SavingsAccount * SavingsAccount::clone()
{
	return new SavingsAccount(*this);
}

void SavingsAccount::setInterestRate(const int rate)
{
	this->interestRate = rate;
}

const double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(const int deposit)
{
	int temp = 0;
	temp = deposit + getBalance();
	setamount(temp);
}

bool SavingsAccount::withdraw(const int withdraw)
{
	if (withdraw <= getBalance())
	{
		int temp = 0;
		temp = getBalance() - withdraw;
		setamount(temp);
		return true;
	}
	std::cout << "Not enough money!\n";
	return false;
}

void SavingsAccount::display()
{
	std::cout << "Account type:Savings account iban: " << getiban() << " ownerid: " << getownerid() <<" interest Rate: "<<getInterestRate()<<" Balance: " << getBalance()<<"\n";
}
