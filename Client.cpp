#include "Client.h"
#include "Car.h"
#include "Driver.h"

#include <string>
#include <iostream>

using namespace std;

Client::Client(int id, string j)
{
	this->client_ID = id;
	this->jmeno = j;
}
Client::Client(int id, string j, string destinace, int vzdalenost)
{
	this->client_ID = id;
	this->jmeno = j;
	this->destinace = destinace;
	this->vzdalenost_od_des = vzdalenost;
}

void Client::Hlaska_odvoz()
{
	cout << "Klient " << jmeno << " pojede autem " << jeho_odvoz->Get_typ() << " znacky " << jeho_odvoz->Get_znacka() << endl;
	cout << "Jeho ridic bude " << jeho_ridic->Get_jmeno() << " s ratingem " << jeho_ridic->Get_rating() << ", vekem "<<jeho_ridic->Get_vek() << " a pojede " << Get_vzdalenost() << "km" << endl;
	cout << "Sazba bude: " << jeho_odvoz->Vypocet_ceny(Get_vzdalenost()) << endl;
	cout << "1km stoji: " << jeho_odvoz->Get_cena_km() << endl;
	cout << endl;
}