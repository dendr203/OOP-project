#include "Car.h"



//Car_osobni
Car_osobni::Car_osobni(int ID, string znac, int pocet_ms, double cena_km, int pocet_neh, Driver* ridic) : Car_taxi()
{
	this->carID = ID;
	this->znacka = znac;
	this->pocet_mist = pocet_ms;
	this->cena_km = cena_km;
	this->pocet_nehod = pocet_neh;
	this->ridic = ridic;
	this->typ = "Osobni";
}

double Car_osobni::Vypocet_ceny(double vzdalenost)
{
	return vzdalenost * cena_km;
}



//Car_supersport

Car_supersport::Car_supersport(int ID, string znac, int pocet_mist, double cena_km, int max_sped, Driver* ridic) : Car_taxi()
{
	this->carID = ID;
	this->znacka = znac;
	this->pocet_mist = pocet_mist;
	this->cena_km = cena_km;
	this->max_speed = max_sped;
	this->ridic = ridic;
	this->typ = "Supersport";
}

double Car_supersport::Vypocet_ceny(double vzdalenost)
{
	return vzdalenost * cena_km;
}

