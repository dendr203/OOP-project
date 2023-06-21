#include "Car.h"
#include "Driver.h"
#include "Taxi.h"
#include "Client.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	Taxi* taxi = new Taxi("Taxi Rychly");			//vytvo�en� taxislu�by
	taxi->Add_driver("Jirka", 20, 4.5);				//p�id�v�n� �idi��
	taxi->Add_driver("Daniel", 20, 2.2);


	taxi->Add_osobni("Mercedes", 4, 20, 0, taxi->Get_ridice(1));	//vytvo�en� aut s p�edem p�i�azen�m �idi�e podle ID
	taxi->Add_super("Audi", 2, 100, 200, nullptr);					//vytvo�en� auta bez �idi�e
	taxi->Get_auto("Audi")->Set_ridic(taxi->Get_ridice("Jirka"));	//nastaven� �idi�e a� pozd�ji podle jm�na
	taxi->Add_driver("Ondrej", 30, 3.9);
	taxi->Add_super("Lamborgini", 1, 200, 300, taxi->Get_ridice(2));

	taxi->Add_client("Janik");										//vytvo�en� clienta bez destinace
	taxi->Add_client("David", "Novy jicin", 20);					//vytvo�en� clienta s destinac�
	taxi->Get_client(1)->Set_destinace("Ostrava", 50);				//nastaven� destinace clienta podle ID pozd�ji
	taxi->Get_client(1)->Set_odvoz(taxi->Get_auto(1));				//nastaven� odvozu clientova podle jeho ID 


	//v�pisy
	cout << taxi->Get_nazev_firmy() << endl;
	cout << "------------------------------------" << endl;
	cout << "Ve firme mame " << taxi->Get_pocet_ridicu() << " ridicu a " << taxi->Get_pocet_aut() << " aut" << endl;
	cout << endl;
	taxi->vypis_aut();
	taxi->vypis_ridicu();
	taxi->vypis_clientu();
	
	cout << "Vypis klienta a jeho odvozu:" << endl;
	taxi->Get_client(1)->Hlaska_odvoz();

	cout << "Ted vyzkousime mazat ruzne polozky na ruznych pozicich" << endl;
	taxi->Delete_driver(2);		//maz�n� �idi�e s ID=2 mazat lze pouze podle ID
	taxi->Delete_car(2);		//maz�n� auta s ID=1
	taxi->Delete_client(2);
	cout << endl;

	delete taxi;


	return 0;
}