// number 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

int main()
{
	Car a("tcmake", "tcmodel", "tccolor", 1200, 120);
	a.details();
	Truck b("ttmake", "ttmodel", "ttcolor", 1500, 200, 100);
	b.details();
	Motorcycle c("tmmake", "tmmodel", "tmcolor", 1300, 110, "tmtype");
	c.details();
    return 0;
}

