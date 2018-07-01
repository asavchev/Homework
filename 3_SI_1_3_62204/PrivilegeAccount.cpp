#include "stdafx.h"
#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount():Account(),overdraft(0)
{
}

PrivilegeAccount::PrivilegeAccount(const char * iban, const unsigned int ownerid, const int amount, const int overdraft):Account(iban,ownerid,amount)
{
	this->overdraft=overdraft;
}

PrivilegeAccount * PrivilegeAccount::clone()
{
	return new PrivilegeAccount(*this);
}

const int PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::deposit(const int deposit)
{
	int temp = 0;
	temp = deposit + getBalance();
	setamount(temp);
}

bool PrivilegeAccount::withdraw(const int withdraw)
{
	if (withdraw <= (getBalance()+overdraft))
	{
		int temp = 0;
		temp = getBalance() - withdraw;
		setamount(temp);
		return true;
	}
	std::cout << "Not enough money!\n";
	return false;
}

void PrivilegeAccount::display()
{
	std::cout << "Account type:Privilage account iban: " << getiban() << " ownerid: " << getownerid() <<" Overdraft: "<<getOverdraft()<< " Balance: " << getBalance() << "\n";
}
