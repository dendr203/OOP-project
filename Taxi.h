#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Driver.h"
#include "Car.h"
#include "Client.h"

using namespace std;

class Taxi
{
private:
	static int pocet_ridicu;
	static int pocet_aut;
	static int pocet_klientu;	
	string nazev_firmy;
	vector <Driver*> ridici;
	vector <Car_taxi*> auta;
	vector <Client*> klienti;

public:
	Taxi(string nazev_firmy);
	~Taxi();

	int Get_pocet_ridicu() { return this->pocet_ridicu; }
	int Get_pocet_aut() { return this->pocet_aut; }
	string Get_nazev_firmy() { return this->nazev_firmy; }

	Driver* Get_ridice(string jmeno);
	Driver* Get_ridice(int kod);
	void Add_driver(string jmeno, int vek, double rating);
	void Delete_driver(int kod);

	Car_taxi* Get_auto(string jmeno);
	Car_taxi* Get_auto(int kod);
	void Add_osobni(string znac, int pocet_ms, double cena_km, int shuttle_o, Driver* ridic);
	void Add_super(string znac, int pocet_ms, double cena_km, int max_speed, Driver* ridic);
	void Delete_car(int kod);

	void vypis_aut();
	void vypis_ridicu();
	void vypis_clientu();

	Client* Get_client(string jmeno);
	Client* Get_client(int kod);
	void Add_client(string jmeno);
	void Add_client(string jmeno, string destinace, int vzdalenost);
	void Delete_client(int kod);


};

