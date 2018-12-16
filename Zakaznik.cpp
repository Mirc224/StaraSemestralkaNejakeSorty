#include "Zakaznik.h"
#include "Udaj.h"



Zakaznik::Zakaznik(std::string meno, std::string priezvisko, std::string psc)
{
	m_udaje.emplace("ID", new IdentifikacneCislo(""));
	m_udaje.emplace("Meno",new Meno(meno));
	m_udaje.emplace("Priezvisko", new Priezvisko(priezvisko));
	m_udaje.emplace("PSC", new PSC(psc));
	//m_udaje.emplace("PSC", new PSC(psc));
	for (auto &p : m_udaje)
	{
		std::cout << p.second->getValue() << " ";
	}
	std::cout << std::endl;
}

std::map<std::string,Udaj*>& Zakaznik::getUdaje()
{
	return m_udaje;
}

Zakaznik::~Zakaznik()
{
	std::map<std::string, Udaj*>::iterator it;
	for (auto &p : m_udaje)
	{
		delete p.second;
	}
}

PSC::PSC(std::string PSC): Udaj("PSC"), m_PSC(PSC)
{
}

PSC::PSC(): Udaj("PSC")
{
}

PSC::~PSC()
{
}

Priezvisko::Priezvisko(std::string priezvisko): Udaj("Priezvisko"), m_priezvisko(priezvisko)
{
}

Priezvisko::Priezvisko(): Udaj("Priezvisko")
{
}

Priezvisko::~Priezvisko()
{
}

Meno::Meno(std::string meno): Udaj("Meno"), m_meno(meno)
{
}

Meno::Meno(): Udaj("Meno")
{
}

Meno::~Meno()
{
}

IdentifikacneCislo::IdentifikacneCislo(): Udaj("ID"), poradoveCisloZ(0)
{
}

IdentifikacneCislo::IdentifikacneCislo(std::string par): Udaj("ID"), poradoveCisloZ(IdentifikacneCislo::GPorCis)
{
	IdentifikacneCislo::GPorCis++;
}

IdentifikacneCislo::~IdentifikacneCislo()
{
}
