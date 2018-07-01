#pragma once
#include <vector>
#include "Customer.h"
#include "Currentaccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
class Bank
{
private:
	char* name;
	char* address;
	Customer* customers;
	std::vector<Account*>accounts;
	int custcount=0;
public:
	Bank();
	Bank(const char* name, const char* address);
	Bank(const Bank& other);
	Bank& operator=(const Bank& rhs);
	~Bank();

	void setname(const char* name);
	void setaddress(const char* address);

	const char* getname()const;
	const char* getaddress()const;

	void clearacc();

	void withdraw(const char* iban,const int amount);
	void deposit(const char* iban,const int amount);
	bool notfound(const unsigned int customerid);
	void addCustomer(const unsigned int customerid, const char* name, const char* address);
	void listCustomers();
	void deleteCustomer(const unsigned int customerid);
	void addAccount(const char* accountType, const char* iban, const unsigned int ownerid, const int amount);
	void deleteAccount(const char* iban);
	void listAccounts();
	void listCustomerAccounts(const unsigned int customerid);
	void transfer(const char* fromIBAN, const char* toIBAN, const int amount);
	void display();
};
