#pragma once
#include "Databaza.h"
#include "Zakaznik.h"
#include "Udaj.h"
#include <vector>
#include <string>	
class DatabazaZakaznikov : public Databaza
{
public:
	static std::string key;
	DatabazaZakaznikov(std::string nazov);
	void vypisZaznam();
	void vypisVyber();
	void vypisVsetkych();
	void refresh();
	void vlozZakaznika(Zakaznik* zak);
	bool pridajDoDatabazy();
	bool odstranZDatabazy();
	bool hladaj();
	bool vyber();
	bool vycistiVyber();
	virtual ~DatabazaZakaznikov();
private:
	std::vector<Zakaznik*> vyhladaj();
	void vypisZvolenuCast(std::vector<Zakaznik*>& tempZak);
	std::vector<Zakaznik*> m_zakaznici;
	std::vector<Zakaznik*> m_zobrZak;
	std::vector<Zakaznik*> m_vybratyZak;
	std::string m_NazovDatabzy;


};

