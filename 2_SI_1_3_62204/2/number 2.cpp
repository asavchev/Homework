// number 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Settings.h"

int main()
{
	Settings<int> a;
	std::cout << a.count() << "\n";
	a.set("test1", 123);
	a.print();
	std::cout << a.count() << "\n";
	a.set("test2", 456);
	a.print();
	std::cout << a.count() << "\n";
	a.get("test2", 143);
	a.print();
    return 0;
}

