#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Driver.h"

using namespace std;

//ryze abstraktní tøída
class Car
{	
public:
	virtual double Vypocet_ceny(double vzdalenost) = 0;
};


class Car_taxi : public Car
{
protected:
	int carID;
	string znacka;
	int pocet_mist;
	double cena_km;
	string typ;

	Driver* ridic = nullptr;

public:
	int Get_carID() { return this->carID; }
	string Get_znacka() { return this->znacka; }

	void Set_ridic(Driver* ridic) { this->ridic = ridic; }
	void Delete_ridic() { this->ridic = nullptr; }
	void Set_cena_km(int new_cena) { this->cena_km = new_cena; }
	double Get_cena_km() { return this->cena_km; }
	Driver* Ger_ridic() { return this->ridic; }
	string Get_typ() { return this->typ; }

};



class Car_osobni : public Car_taxi
{
private:
	int pocet_nehod;
public:
	Car_osobni(int ID, string znac, int pocet_mist, double cena_km, int pocet_neh, Driver* ridic);
	
	double Vypocet_ceny(double vzdalenost) override;
};

class Car_supersport : public Car_taxi
{
private:
	int max_speed;
public:
	Car_supersport(int ID, string znac, int pocet_mist, double cena_km, int max_speed, Driver* ridic);

	double Vypocet_ceny(double vzdalenost) override;
};


