// ConsoleApplication42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ElectricNet.h"

int main()
{
	ElectricDevice a("first", 200), b("second", 100), c("third", 550), d("fourth", 150), e("fifth", 400);
	ElectricNet net(500);
	++net;
	++net;
	++net;
	net += a;
	net += b;
	net = net+c;
	net += d;
	net = net + e;
	net.print();
	--net;
	net -= b;
	net = net - c;
	net.print();
	net["first"];
	return 0;
}

