#pragma once
#include "Car.h"
#include "Driver.h"

#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
	int client_ID;
	string jmeno;
	string destinace;
	int vzdalenost_od_des;

	Driver* jeho_ridic;
	Car_taxi* jeho_odvoz;
public:
	Client(int id, string j);
	Client(int id, string j, string destinace, int vzdalenost);

	int Get_id() { return this->client_ID; }
	string Get_jmeno() { return this->jmeno; }
	string Get_destinaci() { return this->destinace; }
	void Set_destinace(string destinace, int vzdalenost) { this->destinace = destinace; this->vzdalenost_od_des = vzdalenost; }
	int Get_vzdalenost() { return this->vzdalenost_od_des; }

	void Set_odvoz(Car_taxi* odvoz) { this->jeho_odvoz = odvoz, this->jeho_ridic = odvoz->Ger_ridic(); }
	void Hlaska_odvoz();

};

