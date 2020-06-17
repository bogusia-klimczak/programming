#include "Kupon.h"

using namespace std;


Kupon::Kupon()
{
	for (int i = 0; i < 6; i++)
	{
		m_kupon[i] = 0;
	}
	srand(time(NULL));
}


bool Kupon::SprawdzCzyIstnieje(Kupon k, int liczba)
{
	for (int i = 0; i < 6; i++)
	{
		if (m_kupon[i] == 0)
		{
			return false;
		}
		if (liczba == m_kupon[i])
		{
			return true;
		}
	}
	return false;
}


Kupon Kupon::Losuj()
{
	int liczbaLos;

	for (int i = 0; i < 6; i++)
	{
		liczbaLos = rand() % 49 + 1;
		if (SprawdzCzyIstnieje(*this, liczbaLos))
		{
			i--;
			continue;
		}
		m_kupon[i] = liczbaLos;
	}
	sort(this->m_kupon, this->m_kupon + 6);
	return *this;
}

Kupon* Kupon::LosujSerie(Kupon* kupony, int ilosc)
{
	srand(time(NULL));
	Kupon kupon;
	for (int i = 0; i < ilosc; i++)
	{
		kupony[i] = kupon.Losuj();
	}
	return kupony;
}

void Kupon::WypiszKupon()
{
	for (int i = 0; i < 6; i++)
	{
		cout << m_kupon[i] << "\t";
	}
	cout << endl;
}

void Kupon::WypiszSerie(Kupon* kupony, int ilosc)
{
	for (int i = 0; i < ilosc; i++)
	{
		cout << i+1 << ". ";
		kupony[i].WypiszKupon();
	}
}

void Kupon::ZapiszPoj()
{
	ofstream plik;
	plik.open("Lotto.txt");
	for (int i = 0; i < 6; i++)
	{
		plik << this->m_kupon[i] << "\t";
	}
	plik << endl;
	plik.close();
}

void Kupon::ZapiszKil(Kupon* kupony, int ilosc)
{

	ofstream plik;
	plik.open("Lotto.txt");
	for (int i = 0; i < ilosc; i++)
	{
		plik << i + 1 << ".	";
		for (int j = 0; j < 6; j++)
		{
			plik << this[i].m_kupon[j] << "\t";
		}
		plik << endl;
	}
	plik << endl;
	plik.close();
}