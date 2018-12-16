#include "DatabazaZakaznikov.h"
#include "Databaza.h"
#include <algorithm>

std::string DatabazaZakaznikov::key = "ID";

DatabazaZakaznikov::DatabazaZakaznikov(std::string nazov) : Databaza(), m_NazovDatabzy(nazov)
{
	std::vector<Udaj> temp;
	temp.push_back(Udaj("ID"));
	temp.push_back(Udaj("Meno"));
	temp.push_back(Udaj("Priezvisko"));
	temp.push_back(Udaj("PSC"));
	setParametre(temp);
}

void DatabazaZakaznikov::vypisZaznam()
{
	vypisZvolenuCast(m_zobrZak);
}

void DatabazaZakaznikov::vypisVyber()
{
	m_zobrZak.clear();
	for (auto &p : m_vybratyZak)
	{
		m_zobrZak.push_back(p);
	}
}

void DatabazaZakaznikov::vypisVsetkych()
{
	m_zobrZak.clear();
	for (auto &p : m_zakaznici)
	{
		m_zobrZak.push_back(p);
	}
}

void DatabazaZakaznikov::refresh()
{
	m_zobrZak.clear();
	for (auto &p : m_zakaznici)
	{
		m_zobrZak.push_back(p);
	}
}

void DatabazaZakaznikov::vlozZakaznika(Zakaznik* zak)
{
	m_zakaznici.push_back(zak);
	refresh();
}

bool DatabazaZakaznikov::pridajDoDatabazy()
{
	std::vector<std::string> zParam;
	std::cout << "\t";
	for (auto &p : getM_Parametre())
	{
		std::string temp;
		if (p.compare("ID") != 0)
		{
			std::cout << p << ": ";
			std::getline(std::cin, temp);
			std::cout << "\t";
			if (temp.size() > 0)
			{
				zParam.push_back(temp);
			}
			else
			{
				std::cout << "Prazdny parameter" << std::endl;
				return false;
			}
		}

	}
	if (zParam.size() == getM_parametreSize() - 1)
	{
		int i = 0;
		std::string tempString = zParam.back();
		for (int i = 0; i < tempString.length(); ++i)
		{
			std::locale loc;
			if (!std::isdigit(tempString[i], loc))
			{
				std::cout << "PSC musi byt cislo" << std::endl;
				return false;
			}
		}
		if (tempString.length() == 5)
		{
			vlozZakaznika(new Zakaznik(zParam.at(i), zParam.at(i + 1), zParam.at(i + 2)));
			return true;
		}
		else
		{
			std::cout << "PSC je 5 ciferne cislo!" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Nespravny pocet parametrov" << std::endl;
		return false;
	}
}

bool DatabazaZakaznikov::odstranZDatabazy()
{
	if (m_vybratyZak.size() == 0)
	{
		std::cout << "Vas vyber je prazdny! \n";
		return false;
	}
	else
	{
		for (auto &p : m_vybratyZak)
		{
			int index = std::distance(m_zakaznici.begin(), std::find(m_zakaznici.begin(), m_zakaznici.end(), p));
			Zakaznik* temp = m_vybratyZak.at(index);
			delete temp;
			if (index > 0)
			{
				m_zakaznici.erase(m_zakaznici.begin() + index - 1);
			}
			else
			{
				m_zakaznici.erase(m_zakaznici.begin());
			}
		}
		m_vybratyZak.clear();
		vypisVsetkych();
		return true;
	}
}

bool DatabazaZakaznikov::hladaj()
{
	std::vector<Zakaznik*> tempZak = vyhladaj();
	if (tempZak.size() != 0)
	{
		m_zobrZak.clear();
		for (auto &p : tempZak)
		{
			m_zobrZak.push_back(p);
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool DatabazaZakaznikov::vyber()
{
	std::vector<Zakaznik*> tempZak = vyhladaj();
	if (tempZak.size() != 0)
	{
		for (auto &p : tempZak)
		{
			m_vybratyZak.push_back(p);
		}
		return true;
	}
	else
	{
		return false;
	}

}

bool DatabazaZakaznikov::vycistiVyber()
{
	if (m_vybratyZak.size() != 0)
	{
		m_vybratyZak.clear();
		return true;
	}
	else
	{
		return false;
	}
}


DatabazaZakaznikov::~DatabazaZakaznikov()
{
	for (auto &p : m_zakaznici)
	{
		delete p;
	}
}


std::vector<Zakaznik*> DatabazaZakaznikov::vyhladaj()
{
	std::vector<std::string> tempU = getM_Parametre();
	std::vector<std::string> zadParam;
	std::vector<std::string> pozadovanyUdaj;
	std::vector<Zakaznik*> vyhovujuciZak;
	std::cout << "\t";
	for (auto &p : tempU)
	{
		std::string temp;
		std::cout << p << ": ";
		std::getline(std::cin, temp);
		std::cout << "\t";
		if (temp.length() != 0)
		{
			pozadovanyUdaj.push_back(p);
			zadParam.push_back(temp);
		}
	}
	if (zadParam.size() == 0)
	{
		std::cout << "Nezadali ste ziadne kriterium vyhladavania!" << std::endl;
		return vyhovujuciZak;
	}
	for (auto &p : m_zakaznici)
	{
		bool test = false;
		for (int i = 0; i < pozadovanyUdaj.size(); ++i)
		{
			if (p->getUdaje().find(pozadovanyUdaj.at(i))->second->getValue().compare(zadParam.at(i)) == 0)
			{
				test = true;
			}
			else
			{
				test = false;
				break;
			}
		}
		if (test)
		{
			vyhovujuciZak.push_back(p);
		}
		else
		{
			continue;
		}
	}
	return vyhovujuciZak;
}

void DatabazaZakaznikov::vypisZvolenuCast(std::vector<Zakaznik*>& tempZak)
{
	if (this->getZobParametre().size() > 0)
	{
		this->vypisHlavicku();
		for (auto& zobZ : tempZak)
		{
			for (auto &p : getZobParametre())
			{
				/*if (p.compare("PSC") == 0)
					std::cout << "\t";*/
				std::cout << zobZ->getUdaje().find(p)->second->getValue() << "\t";
				if (zobZ->getUdaje().find(p)->second->getValue().length() < 8)
					std::cout << "\t";
			}
			std::cout << std::endl;
		}
	}
}
