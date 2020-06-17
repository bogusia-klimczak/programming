#include <iostream>

#include <string>
#include <vector>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "GENERATOR.h"

using namespace std;

int defense_int_input(string text, int min_val, int max_val)
{
	int value;
	cout << text;
	cin >> value;

	while (min_val > value || value > max_val)
	{
		cout << "Wartosc musi byc nie mniejsza niz " << min_val << " i nie wieksza niz " << max_val << endl;
		cout << text;
		cin >> value;
	}
	return value;
}

int display_menu()
{
	int menu_selection = 0;
	cout << endl
		 << "Menu:" << endl;
	cout << "1 - Generowanie liczb" << endl;
	cout << "2 - Sortowanie liczb" << endl;
	cout << "3 - Wywietlanie liczb" << endl;
	cout << "4 - Zapisywanie liczb do pliku" << endl;
	cout << "5 - Koniec programu" << endl;

	cout << endl;
	menu_selection = defense_int_input("Wybierz operacje: ", 1, 5);

	return menu_selection;
}

int main()
{
	srand(time(NULL));

	cout << "Generator liczb losowych." << endl;
	int low_range = 0, high_range = 0, amount_of_numbers = 0, number_of_attampts = 0;
	vector<GENERATOR> gen_list;
	gen_list.clear(); // gen_list = []

	int menu_selection = display_menu();

	while (menu_selection < 5)
	{
		switch (menu_selection)
		{
		case 1:
			low_range = defense_int_input("Podaj dolny zakres: ", 0, 1000);
			high_range = defense_int_input("Podaj grny zakres: ", low_range, 1000);
			amount_of_numbers = defense_int_input("Ile liczb chcesz wygenerowac?: ", 0, 100);
			number_of_attampts = defense_int_input("Ile losowan chcesz przeprowadzic?: ", 0, 100);
			gen_list.clear(); // gen_list = []
			for (int i = 0; i < number_of_attampts; i++)
			{
				GENERATOR gen(low_range, high_range, amount_of_numbers);
				gen_list.push_back(gen);
			}
			break;
		case 2:
			for (int i = 0; i < number_of_attampts; i++)
			{
				gen_list[i].sort();
			}
			cout << "Wartosci posortowano." << endl;
			break;
		case 3:
			cout << "Wygenerowane liczby to:" << endl;
			for (int i = 0; i < number_of_attampts; i++)
			{
				gen_list[i].show();
			}
			break;
		case 4:
			ofstream outfile;
			outfile.open("numbers_from_Python.txt", ios::trunc);

			for (int i = 0; i < number_of_attampts; i++)
			{
				gen_list[i].save(outfile);
			}

			outfile.close();

			cout << "Zapisano do pliku" << endl;
			break;
		}

		menu_selection = display_menu();
	}
}