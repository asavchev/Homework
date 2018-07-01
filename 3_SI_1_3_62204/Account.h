#pragma once
#include <iostream>
#include <cstring>
class Account
{
private:
	char* iban;
	unsigned int ownerid;
	int amount;
public:
	Account();
	Account(const char* iban, const unsigned int ownerid, const int amount);
	Account(const Account& other);
	Account& operator=(const Account & rhs);
	virtual ~Account();
	virtual Account* clone()=0;

	void setiban(const char* iban);
	void setownerid(const unsigned int ownerid);
	void setamount(const int amount);

	const char* getiban()const;
	const unsigned int getownerid()const;
	const int getBalance()const;

	virtual void deposit(const int deposit)=0;
	virtual bool withdraw(const int withdraw)=0;
	virtual void display()=0;
};
