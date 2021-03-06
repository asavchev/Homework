// ConsoleApplication52.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Product.h"
#include "Store.h"

int main()
{
	
	Store GSMStore;
	int br = 0,num;
	double price;
	char key,brand[64],model[64];
	std::cout << "     Welcome to my GSM Store\n";
	while (br == 0)
	{
		std::cout << "Choose what to do:\n";
		std::cout << "Press A and enter to Add a new product\n";
		std::cout << "Press X and enter to Delete a product\n";
		std::cout << "Press C and enter to Change product\n";
		std::cout << "Press D and enter to Display products\n";
		std::cout << "Press Q and enter to Quit\n";
		std::cin >> key;
		if (key == 'q' || key == 'Q')
		{
			br = 1;
		}
		else if (key == 'd' || key == 'D')
		{
			GSMStore.Display();
		}
		else if (key=='c'||key=='C' )
		{ 
			std::cout << "Choose and element to change by writhing its SKU and pressign Enter:\n";
			GSMStore.Display();
			if (GSMStore.Getdiffnum() != 0)
			{
				std::cin >> num;
				std::cout << "Enter new brand:\n";
				std::cin.ignore();
				std::cin.getline(brand, 64);
				std::cout << "Enter new model:\n";
				std::cin.getline(model, 64);
				std::cout << "Enter new price:\n";
				std::cin >> price;
				Product test(brand, model, price);
				GSMStore.ChangeProduct(num, test);
			}
		}
		else if (key == 'x' || key == 'X')
		{
			std::cout << "Choose and element to delete by writhing its SKU and pressign Enter:\n";
			GSMStore.Display();
			if (GSMStore.Getdiffnum() != 0)
			{
				std::cin >> num;
				GSMStore.DeleteProduct(num);
			}
		}
		else if (key == 'a' || key == 'A')
		{
			std::cout << "Enter new brand:\n";
			std::cin.ignore();
			std::cin.getline(brand, 64);
			std::cout << "Enter new model:\n";
			std::cin.getline(model, 64);
			std::cout << "Enter new price:\n";
			std::cin >> price;
			Product test(brand, model, price);
			GSMStore.AddProduct(test);
		}
		else
		{
			std::cout << "Wrong input!!!\n";
			std::cout << "        Try again:\n";
		}
		std::cout << '\n';
		std::cout << '\n';
		std::cout << '\n';
	}
	std::cout << "Goodbye sir!\n";
    return 0;
}

