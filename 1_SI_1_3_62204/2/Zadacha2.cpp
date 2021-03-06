// ConsoleApplication45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BrowserHistory.h"

int main()
{
	BrowserHistory history1,history2,history3;
	HistoryEntry a(4, "abv");
	HistoryEntry b(4, "mail");
	HistoryEntry c(5, "facebook");
	HistoryEntry d(8, "abv");
	history1.AddEntry(a);
	history1.AddEntry(b);
	history2.AddEntry(c);
	history2.AddEntry(d);
	std::cout << "The entries in history1 are:\n";
	history1.print();
	std::cout << std::endl;
	std::cout << "The entries in history2 are:\n";
	history2.print();
	std::cout << std::endl;
	history3 = history1 + history2;
	std::cout << "The combined entries in history1 and history2 are(history3):\n";
	history3.print();
	std::cout <<"The number of entries in history3 in April is:"<< history3.Month(4) << std::endl;
	std::cout <<"The month with the most entries in history3 is:"<< history3.MostMonth() << std::endl;
    return 0;
}

