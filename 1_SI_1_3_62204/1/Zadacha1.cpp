//Zabelejka
//vseki edin znak (+ , - , / , * , %) trqbva da e obragen ot intervali, primer: " * "
//osven ako ne e znak za otricatelno chislo, togava trqbva da e slepen s chisloto, primer: " -42 "
//primer na pravilni vhodni danni: "32 -100 + -42 * 2 /"

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Stack.h"
int calculate(char* a)
{
	int size, stoinost, x,y,z,br=0;
	Stack number;
	for (int i = 0; i < 1024; i++)
	{
		if (a[i] == '\0')
		{
			break;
		}
		else if (a[i] == '-' && (a[i + 1] >= '0' && a[i + 1] <= '9'))
		{
			br = 1;
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			x = a[i] - 48;
			if (a[i - 1] >= '0' && a[i - 1] <= '9')
			{
				x += (number.pop() * 10);
			}
			if (br == 1 && a[i + 1] == ' ')
				x = (x*-1);
			number.push(x);
		}
		else if (a[i] == ' ')
		{
			br = 0;
		}
		else if (a[i] == '*')
		{
			y = number.pop();
			z = number.pop();
			stoinost = z * y;
			number.push(stoinost);
		}
		else if (a[i] == '+')
		{
			y = number.pop();
			z = number.pop();
			stoinost = z + y;
			number.push(stoinost);
		}
		else if (a[i] == '-'&&(a[i+1]=='\0' || a [i+1] == ' '))
		{
			y = number.pop();
			z = number.pop();
			stoinost = z - y;
			number.push(stoinost);
		}
		else if (a[i] == '%')
		{
			y = number.pop();
			z = number.pop();
			stoinost = z % y;
			number.push(stoinost);
		}
		else if (a[i] == '/')
		{
			y = number.pop();
			z = number.pop();
			stoinost = z / y;
			number.push(stoinost);
		}
	}
	return stoinost;
}
int main()
{
	int result;
	char polskizapis[1024];
	std::cin.getline(polskizapis, 1024);
	result = calculate(polskizapis);
	std::cout << result << std::endl;
    return 0;
}

