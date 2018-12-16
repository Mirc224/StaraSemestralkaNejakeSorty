#include "Vykonavac.h"



Vykonavac::Vykonavac(Databaza* dat) : m_vykonavana(dat)
{
	m_prikazy.push_back("koniec");
	m_prikazy.push_back("vypis");
	m_prikazy.push_back("pridaj");
	m_prikazy.push_back("hladaj");
	m_prikazy.push_back("odstran");
	m_prikazy.push_back("vyber");
}

std::vector<std::string> Vykonavac::nacitajParametre(std::string retazParam)
{
	std::vector<std::string> parametre;
	while (retazParam.length() > 0)
	{
		std::string pomocny;
		int temp = 0;
		std::string udajS;
		if (retazParam.find(' ') != std::string::npos)
		{
			temp = retazParam.find(' ');
			udajS = retazParam.substr(0, temp);
			pomocny = retazParam.substr(temp + 1);
		}
		else
		{
			temp = retazParam.length();
			udajS = retazParam.substr(0, temp);
			pomocny = retazParam.substr(temp);
		}
		retazParam = pomocny;
		if (udajS.length() != 0)
		{
			std::string temp = "";
			std::locale loc;
			for (int i = 0; i < udajS.length(); ++i)
			{
				temp += std::tolower(udajS.at(i), loc);
			}
			parametre.push_back(temp);
		}
	}
	return parametre;
}

bool Vykonavac::vykonaj()
{
	std::string temp;
	std::getline(std::cin, temp);
	std::vector<std::string> parametre = nacitajParametre(temp);
	prikazy volba = prikazy(-1);
	bool test = true;
	for (auto &s : parametre)
	{
		{
			int i = 0;
			for (auto &p : m_prikazy)
			{
				if (p.compare(s) == 0)
				{
					if (volba != ziadny)
					{
						test = false;
						break;
					}
					volba = prikazy(i);
				}
				++i;
			}
		}
	}
	if (!test || volba == ziadny)
	{
		std::cout << "Nespravne zadana poziadavka" << std::endl;
		return true;
	}
	else
	{
		parametre.erase(parametre.begin());
		if (m_vykonavana != nullptr)
		{
			switch (volba)
			{
			case vypis:
			if (m_vykonavana->setZobrazParam(parametre))
					m_vykonavana->vypisZaznam();
				break;
			case pridaj:
				if (m_vykonavana->pridajDoDatabazy())
				{
					std::cout << "Zaznam bol pridany!" << std::endl;
				}
				else
				{
					std::cout << "Pridavanie neuspesne!" << std::endl;
				}
				break;
			case hladaj:
				if (m_vykonavana->hladaj())
				{
					std::cout << "Hladanie uspesne!" << std::endl;
					m_vykonavana->vypisZaznam();
				}
				else
				{
					std::cout << "Hladanie bolo neuspesne!" << std::endl;
				}
				break;
			case odstran:
				if (m_vykonavana->odstranZDatabazy())
				{
					std::cout << "Vyber bol odstraneny! \n";
				}
				else
				{
					std::cout << "Odstranovanie zlyhalo \n";
				}
				break;
			case vyber:
				if (m_vykonavana->vyber())
				{
					std::cout << "Vyber obsahuje novy zaznam \n";
				}
				else
				{
					std::cout << "Neboli vybrate ziadne zaznamy! \n";
				}
				break;
			case koniec:
				return false;
				break;
			}

		}
	}
	return true;
}


Vykonavac::~Vykonavac()
{
}
