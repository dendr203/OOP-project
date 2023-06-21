#include "Driver.h"
#include <string>
#include <iostream>

using namespace std;

Driver::Driver(string j, int v, double r, int ID)
{
	this->jmeno = j;
	this->vek = v;
	this->rating = r;
	this->driverID = ID;
}

