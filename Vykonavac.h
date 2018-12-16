#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Databaza.h"
class Vykonavac
{
public:
	enum prikazy {ziadny = -1, koniec, vypis, pridaj,hladaj,odstran, vyber};
	Vykonavac(Databaza* dat);
	std::vector<std::string> nacitajParametre(std::string retazParam);
	bool vykonaj();
	void setVykonavana(Databaza* dat) { m_vykonavana = dat; }
	virtual ~Vykonavac();
private:
	Databaza* m_vykonavana;
	std::vector<std::string> m_prikazy;
};

