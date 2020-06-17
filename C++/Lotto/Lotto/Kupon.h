#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <algorithm>

class Kupon
{
private:
	int m_kupon[6];

public:
	Kupon();
	Kupon Losuj();
	Kupon* LosujSerie(Kupon* kupony, int ilosc);
	bool SprawdzCzyIstnieje(Kupon k, int liczbaLos);
	void WypiszKupon();
	void WypiszSerie(Kupon* kupony, int ilosc);
	void ZapiszPoj();
	void ZapiszKil(Kupon* kupony, int ilosc);
};

