#pragma once
#include "Account.h"
class PrivilegeAccount :public Account
{
private:
	int overdraft;
public:
	PrivilegeAccount();
	PrivilegeAccount(const char* iban, const unsigned int ownerid, const int amount, const int overdraft);
    PrivilegeAccount* clone();
	const int getOverdraft()const;
	void deposit(const int deposit);
	bool withdraw(const int withdraw);
	void display();
};
