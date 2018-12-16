#include <iostream>
#include <vector>
#include "Zakaznik.h"
#include "Udaj.h"
#include "Databaza.h"
#include "DatabazaZakaznikov.h"
#include "Vykonavac.h"
int IdentifikacneCislo::GPorCis = 0;
int main(int argc, char* argv[])
{
	//Zakaznik zak1("Miroslav", "Potocar", "02314");
	//Zakaznik zak2("Renata", "Potocarova", "02314");
	//Zakaznik zak3("Lenka", "Potocarova", "02314");
	DatabazaZakaznikov* dat = new DatabazaZakaznikov("Databaza1");
	dat->vlozZakaznika(new Zakaznik("Miroslav", "Potocar", "02314"));
	dat->vlozZakaznika(new Zakaznik("Renata", "Potocarova", "02314"));
	dat->vlozZakaznika(new Zakaznik("Lenka", "Potocarova", "02314"));
	Vykonavac vyk(dat);
	bool test = true;
	while (test)
	{
		test = vyk.vykonaj();
	}
	return 0;
}