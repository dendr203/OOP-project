#pragma once
#include <string>
#include <iostream>

using namespace std;

class Driver
{
private:
	string jmeno;
	int vek;
	double rating;
	int driverID;

public:
	Driver(string j, int v, double r, int ID);

	string Get_jmeno() { return this->jmeno; }
	int Get_vek() { return this->vek; }
	double Get_rating() { return this->rating; }
	int Get_driverID() { return this->driverID; }

};

