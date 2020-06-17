#include <iostream>
#include "Kupon.h"

using namespace std;

void menu(void)
{
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cout << "1. Pojedyncze losowanie" << endl;
	cout << "2. Seria losowan" << endl;
	cout << "3. Eksport do pliku" << endl;
	cout << "k. Koniec programu" << endl;
	cout << endl;
}

int main()
{
	cout << "Witaj w programie do losowania numerow Lotto.\n";
	char wybor = 'h';
	Kupon kupon;
	Kupon kupony[20];
	int ostatnioWybranaOpcja = 0;
	int ileLosow = 0;
	while (wybor != 'k')
	{
		menu();
		cin >> wybor;
		switch (wybor)
		{
		case '1':
			ostatnioWybranaOpcja = 1;
			kupon.Losuj();
			kupon.WypiszKupon();
			break;
		case '2':
			ostatnioWybranaOpcja = 2;
			cout << "Podaj liczbe kuponow do wylosowania: ";
			cin >> ileLosow;
			//kupony = new Kupon[ileLosow];
			kupony->LosujSerie(kupony, ileLosow);
			kupony->WypiszSerie(kupony, ileLosow);
			break;
		case '3':
			if (ostatnioWybranaOpcja == 1)
				kupon.ZapiszPoj();
			else if (ostatnioWybranaOpcja == 2)
				kupony->ZapiszKil(kupony, ileLosow);
			else
				cout << "Nie wylosowano liczb." << endl;
			break;
		default:
			cout << "Wypierz poprawna opcje";
			break;
		}
	}
}