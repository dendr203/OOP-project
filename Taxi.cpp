#include "Taxi.h"
#include "Driver.h"
#include "Car.h"

#include <string>
#include <iostream>

using namespace std;

int Taxi::pocet_ridicu = 0;
int Taxi::pocet_aut = 0;
int Taxi::pocet_klientu = 0;

//taxi èást
Taxi::Taxi(string nazev_firmy)
{
	this->nazev_firmy = nazev_firmy;
}
Taxi::~Taxi()
{
	for (auto& ridic : ridici) {
		delete ridic;
	}
	cout << "Mazu vsechny ridice" << endl;
	ridici.clear();

	for (auto& car : auta)
	{
		delete car;
	}
	cout << "Mazu vsechny auta" << endl;
	auta.clear();

	for (auto& klient : klienti)
	{
		delete klient;
	}
	cout << "Mazu vsechny klienty" << endl;
	klienti.clear();
}


//øidiè èást
Driver* Taxi::Get_ridice(string jmeno)
{
	for (auto& ridic : ridici)
	{
		if (ridic->Get_jmeno() == jmeno)
		{
			return ridic;
		}
	}
	return nullptr;
}
Driver* Taxi::Get_ridice(int kod)
{
	for (auto& ridic : ridici)
	{
		if (ridic->Get_driverID() == kod)
		{
			return ridic;
		}
	}
	return nullptr;
}


void Taxi::Add_driver(string jmeno, int vek, double rating)
{
	Driver* newdriver = new Driver(jmeno, vek, rating, pocet_ridicu+1);

	ridici.push_back(newdriver);
	pocet_ridicu++;
}

void Taxi::Delete_driver(int kod)
{
	int pozice_maz = 0;
	for (int i = 0; i < pocet_ridicu; i++)
	{
		if (ridici[i]->Get_driverID() == kod)
		{
			cout << "Mazu ridice " << ridici[i]->Get_jmeno() << " s kodem " << ridici[i]->Get_driverID() << endl;
			pozice_maz = i;
			delete ridici[i];
			pocet_ridicu--;
			break;
		}
		else if(i == pocet_ridicu - 1)
		{
			cout << "Nikdo takovy neexistuje!!!" << endl;
			return;
		}
	}

	for (unsigned int i = pozice_maz; i < ridici.size() - 1; i++)
	{
		ridici[i] = ridici[i + 1];
	}
	ridici.resize(pocet_ridicu);
}



//automobil èást
Car_taxi* Taxi::Get_auto(string znacka)
{
	for (auto& car : auta)
	{
		if (car->Get_znacka() == znacka)
		{
			return car;
		}
	}
	return nullptr;
}
Car_taxi* Taxi::Get_auto(int kod)
{
	for (auto& car : auta)
	{
		if (car->Get_carID() == kod)
		{
			return car;
		}
	}
	return nullptr;
}

void Taxi::Add_osobni(string znac, int pocet_ms, double cena_km, int shuttle_o, Driver* ridic)
{
	Car_osobni* newcar = new Car_osobni(pocet_aut+1, znac, pocet_ms, cena_km, shuttle_o, ridic);

	auta.push_back(newcar);
	pocet_aut++;
}

void Taxi::Add_super(string znac, int pocet_mist, double cena_km, int max_speed, Driver* ridic)
{
	Car_supersport* newcar = new Car_supersport(pocet_aut+1, znac, pocet_mist, cena_km, max_speed, ridic);
	
	auta.push_back(newcar);
	pocet_aut++;
}

void Taxi::Delete_car(int kod)
{
	int pozice_maz = 0;
	for (int i = 0; i < pocet_aut; i++)
	{
		if (auta[i]->Get_carID() == kod)
		{
			cout << "Mazu auto znacky " << auta[i]->Get_znacka() << " s kodem " << auta[i]->Get_carID() << endl;
			pozice_maz = i;
			delete auta[i];
			pocet_aut--;
			break;
		}
		else if (i == pocet_aut - 1)
		{
			cout << "Zadne takove auto neexistuje!!!" << endl;
			return;
		}
	}

	for (unsigned int i = pozice_maz; i < auta.size() - 1; i++)
	{
		auta[i] = auta[i + 1];		//pøeskládání
	}
	auta.resize(pocet_aut);			//resize vektoru
}


//výpisová èást
void Taxi::vypis_aut()
{	
	cout << "Zde jsou nase auta:" << endl;
	for (auto& car : auta)
	{
		cout << car->Get_typ() << " auto znacky " << car->Get_znacka() << endl;
		cout << "Ridicem tohoto auta je " << car->Ger_ridic()->Get_jmeno() << endl;
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}

void Taxi::vypis_ridicu()
{
	cout << "Zde jsou nasi ridici:" << endl;
	for (auto& ridic : ridici)
	{
		cout << "Ridic " << ridic->Get_jmeno() << " s ID: " << ridic->Get_driverID() << " ma rating " << ridic->Get_rating() << endl;
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}

void Taxi::vypis_clientu()
{
	cout << "Zde jsou nasi klienti:" << endl;
	for (auto& klient : klienti)
	{
		cout << "Klient " << klient->Get_jmeno() << " s ID: " << klient->Get_id() << endl;
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}


//klient èást
Client* Taxi::Get_client(string jmeno)
{
	for (auto& klient : klienti)
	{
		if (klient->Get_jmeno() == jmeno)
		{
			return klient;
		}
	}
	return nullptr;
}
Client* Taxi::Get_client(int kod)
{
	for (auto& klient : klienti)
	{
		if (klient->Get_id() == kod)
		{
			return klient;
		}
	}
	return nullptr;
}

void Taxi::Add_client(string jmeno)
{
	Client* newclient = new Client(pocet_klientu + 1, jmeno);
	klienti.push_back(newclient);

	pocet_klientu++;
}
void Taxi::Add_client(string jmeno, string destinace, int vzdalenost)
{
	Client* newclient = new Client(pocet_klientu + 1, jmeno, destinace, vzdalenost);
	klienti.push_back(newclient);

	pocet_klientu++;
}

void Taxi::Delete_client(int kod)
{
	int pozice_maz = 0;
	for (int i = 0; i < pocet_klientu; i++)
	{
		if (klienti[i]->Get_id() == kod)
		{
			cout << "Mazu klienta " << klienti[i]->Get_jmeno() << " s kodem " << klienti[i]->Get_id() << endl;
			pozice_maz = i;
			delete klienti[i];
			pocet_klientu--;
			break;
		}
		else if (i == pocet_klientu - 1)
		{
			cout << "Zadny takovy klient neexistuje!!!" << endl;
			return;
		}
	}

	for (unsigned int i = pozice_maz; i < klienti.size() - 1; i++)
	{
		klienti[i] = klienti[i + 1];		//pøeskládání
	}
	klienti.resize(pocet_klientu);			//resize vektoru
}
