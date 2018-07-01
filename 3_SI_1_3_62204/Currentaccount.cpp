#include "stdafx.h"
#include "Currentaccount.h"

CurrentAccount::CurrentAccount():Account()
{
}

CurrentAccount::CurrentAccount(const char * iban, const unsigned int ownerid, const int amount):Account(iban,ownerid,amount)
{
}

CurrentAccount * CurrentAccount::clone()
{
	return new CurrentAccount(*this);
}

void CurrentAccount::deposit(const int deposit)
{
	int temp=0;
	temp = deposit + getBalance();
	setamount(temp);
}

bool CurrentAccount::withdraw(const int withdraw)
{
	if (withdraw <= getBalance())
	{
		int temp=0;
		temp = getBalance() - withdraw;
		setamount(temp);
		return true;
	}
	std::cout << "Not enough money!\n";
	return false;
}

void CurrentAccount::display()
{
	std::cout << "Account type:Current account iban: " << getiban() << " ownerid: " << getownerid() << " Balance: " << getBalance() << "\n";
}
