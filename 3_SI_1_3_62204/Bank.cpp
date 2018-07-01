#include "stdafx.h"
#include "Bank.h"

Bank::Bank():name(nullptr),address(nullptr),customers(nullptr)
{
}

Bank::Bank(const char * name, const char * address)
{
	this->name = nullptr;
	this->address = nullptr;
	customers = nullptr;
	setname(name);
	setaddress(address);
}

Bank::Bank(const Bank & other)
{
	name = nullptr;
	address = nullptr;
	customers = nullptr;
	setname(other.getname());
	setaddress(other.getaddress());
	custcount = other.custcount;
	customers = new Customer[custcount];
	for (int i = 0; i < custcount; i++)
	{
		customers[i] = other.customers[i];
	}
	for (std::size_t i = 0; i < other.accounts.size(); ++i)
	{
		    Account* temp = other.accounts[i]->clone();
			accounts.push_back(temp);
	}
}

Bank & Bank::operator=(const Bank & rhs)
{
	if (this != &rhs)
	{
		setname(rhs.getname());
		setaddress(rhs.getaddress());
		custcount = rhs.custcount;
		delete[] customers;
		if (rhs.customers != nullptr)
		{
			customers = new Customer[custcount];
			for (int i = 0; i < custcount; i++)
			{
				customers[i] = rhs.customers[i];
			}
		}
		else
		{
			customers = nullptr;
		}
		for (std::size_t i = 0; i < rhs.accounts.size(); ++i)
		{
			Account* temp = rhs.accounts[i]->clone();
			accounts.push_back(temp);
		}
	}
	return *this;
}

Bank::~Bank()
{
	delete[] name;
	delete[] address;
	delete[] customers;
	clearacc();
}

void Bank::setname(const char * name)
{
	if (name == nullptr)
	{
		delete[] this->name;
		name = nullptr;
	}
	else
	{
		delete[] this->name;
		int size = strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}
}

void Bank::setaddress(const char * address)
{
	if (address == nullptr)
	{
		delete[] this->address;
		address = nullptr;
	}
	else
	{
		delete[] this->address;
		int size = strlen(address) + 1;
		this->address = new char[size];
		strcpy(this->address, address);
	}
}

const char * Bank::getname() const
{
	return this->name;
}

const char * Bank::getaddress() const
{
	return this->address;
}

void Bank::clearacc()
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		delete accounts[i];
	}
}


void Bank::withdraw(const char * iban,const int amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (strcmp(accounts[i]->getiban(), iban) == 0)
		{
			accounts[i]->withdraw(amount);
		}
	}
}

void Bank::deposit(const char * iban,const int amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (strcmp(accounts[i]->getiban(), iban) == 0)
		{
			accounts[i]->deposit(amount);
		}
	}
}

bool Bank::notfound(const unsigned int customerid)
{
	for (int i = 0; i < custcount; i++)
	{
		if (customerid == customers[i].getid())
		{
			return false;
		}
	}
	return true;
}

void Bank::addCustomer(const unsigned int customerid, const char * name, const char * address)
{
	Customer tempcust(customerid, name, address);
	if (custcount == 0)
	{
		custcount++;
		customers = new Customer[1];
		customers[0] = tempcust;
	}
	else if(notfound(customerid))
	{
		Customer* temp;
		temp = new Customer[custcount];
		for (int i = 0; i < custcount; i++)
		{
			temp[i] = customers[i];
		}
		delete[] customers;
		custcount++;
		customers = new Customer[custcount];
		custcount--;
		for (int i = 0; i < custcount; i++)
		{
			customers[i] = temp[i];
		}
		delete[] temp;
		customers[custcount] = tempcust;
		custcount++;
	}
	else
	{
		std::cout << "Already there!\n";
	}
}

void Bank::listCustomers()
{
	if (custcount == 0)
	{
		std::cout << "No customers!\n";
	}
	else
	{
		for (int i = 0; i < custcount; i++)
		{
			customers[i].display();
		}
	}
}

void Bank::deleteCustomer(const unsigned int customerid)
{
	int k = 0,n=0;
	if (custcount > 0)
	{
		for (int i = 0; i < custcount; i++)
		{
			if (customerid == customers[i].getid())
			{
				Customer* temp;
				custcount--;
				temp = new Customer[custcount];
				for (int j = 0; j < i; j++)
				{
					temp[j] = customers[j];
				}
				for (int j = i; j < custcount; j++)
				{
					temp[j] = customers[j++];
				}
				delete[] customers;
				customers = new Customer[custcount];
				for (int j = 0; j < custcount; j++)
				{
					customers[j] = temp[j];
				}
				delete[] temp;
				break;
			}
		}
		do
		{
			n = k;
			for (size_t i = 0; i < accounts.size(); i++)
			{
				if (customerid == accounts[i]->getownerid())
				{
					Account* deleter = accounts[i];
					accounts.erase(accounts.begin() + i);
					delete deleter;
					k ++;
				}
			}
		} while (k >n);
	}
	else
	{
		std::cout << "No customers!";
	}
}

void Bank::addAccount(const char * accountType, const char * iban, const unsigned int ownerid, const int amount)
{
	int k = 0;
	for (int i = 0; i < custcount; i++)
	{
		if (customers[i].getid() == ownerid)
		{
			k--;
			break;
		}
	}
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getiban() == iban)
		{
			k++;
			break;
		}
	}
	if (k >= 0)
	{
		std::cout << "Error\n";
	}
	if (k < 0)
	{
		if ((strcmp(accountType, "Savings Account") == 0)|| (strcmp(accountType, "S") == 0))
		{
			double interestRate;
			std::cout << "Type interest rate:\n";
			std::cin >> interestRate;
			accounts.push_back(new SavingsAccount(iban, ownerid, amount, interestRate));
			std::cout << "Savings Account added!\n";
		}
		else if ((strcmp(accountType, "Current Account") == 0) || (strcmp(accountType, "C") == 0))
		{
			accounts.push_back(new CurrentAccount(iban, ownerid, amount));
			std::cout << "Current Account added\n";
		}
		else if ((strcmp(accountType, "Privilege Account")==0) || (strcmp(accountType, "P") == 0))
		{
			int overdraft;
			std::cout << "Type in overdraft amount:";
			std::cin >> overdraft;
			accounts.push_back(new PrivilegeAccount(iban, ownerid, amount, overdraft));
			std::cout << "Privilege Account added";
		}
		else
		{
			std::cout << "Invalid account type!\n";
		}
	}
}

void Bank::deleteAccount(const char * iban)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (strcmp(iban,accounts[i]->getiban())==0)
		{
			Account* deleter =accounts[i];
			accounts.erase(accounts.begin() + i);
			delete deleter;
		}
	}
}

void Bank::listAccounts()
{
	if (accounts.size()== 0)
	{
		std::cout << "There are no accounts!\n";
	}
	else
	{
		for (size_t i = 0; i < accounts.size(); i++)
		{
			accounts[i]->display();
		}
	}
}

void Bank::listCustomerAccounts(const unsigned int customerid)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (customerid == accounts[i]->getownerid())
		{
			accounts[i]->display();
		}
	}
}

void Bank::transfer(const char * fromIBAN, const char * toIBAN, const int amount)
{
	int k = 0,l,m=1;
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (strcmp(accounts[i]->getiban(), fromIBAN) == 0)
		{
			l = i;
			if (amount > accounts[i]->getBalance())
			{
				k++;
				std::cout << "Not enough money in " << accounts[i]->getiban()<<"\n";
				break;
			}
			if (i == (accounts.size() - 1))
			{
				k++;
				std::cout << "There is no account with that iban\n";
			}
		}
	}
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (strcmp(accounts[i]->getiban(), toIBAN) == 0)
		{
			m = 0;
		}
	}
	if (m != 0)
	{
		std::cout<<"There is no account with that iban\n";
	}
	if(k==0&&m==0)
	{ 
		int newam = 0;
		newam = accounts[l]->getBalance()-amount;
		accounts[l]->setamount(newam);
		for (size_t i = 0; i < accounts.size(); i++)
		{
			if (strcmp(accounts[i]->getiban(), toIBAN) == 0)
			{
				newam = accounts[i]->getBalance()+amount;
				accounts[i]->setamount(newam);
			}
		}
	}
}

void Bank::display()
{
	std::cout << "Bank name: " << getname() << " Address: " << getaddress() << "\n";
	std::cout << "Number of customers: " << custcount << " Number of accounts: " << accounts.size() << "\n";
}
