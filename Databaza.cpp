#include "Databaza.h"
std::string toMalePismena(std::string slovo)
{
	std::string toLowVsp = "";
	for (int i = 0; i < slovo.length(); ++i)
	{
		std::locale loc;
		toLowVsp += std::tolower(slovo.at(i), loc);
	}
	return toLowVsp;
}

Databaza::Databaza()
{
}

void Databaza::setParametre(std::vector<Udaj>& parametre)
{
	for (auto &p : parametre)
	{
		m_parametre.push_back(p.getNazov());
		m_zobrazovanePar.push_back(p.getNazov());
	}
}

void Databaza::vypisHlavicku()
{
	for (auto & nazovUdaju : m_zobrazovanePar)
	{
		std::cout << nazovUdaju << "\t";
		if (nazovUdaju.length() < 8)
		{
			std::cout << "\t";
		}
	}
	std::cout << std::endl;
}


//bool Databaza::pridavanie()
//{
//	std::vector<std::string> zadParam;
//	std::cout << "\t";
//	for (auto &p : m_parametre)
//	{
//		std::string temp;
//		if (p.first.compare("ID") != 0)
//		{
//			std::cout << p.first << ": ";
//			std::getline(std::cin,temp);
//			std::cin.get();
//			std::cout << "\t";
//			if (temp.size() > 0)
//			{
//				zadParam.push_back(temp);
//			}
//			else
//			{
//				std::cout << "Prazdny parameter" << std::endl;
//				return false;
//			}
//		}
//
//	}
//	return pridajDoDatabazy(zadParam);
//}

bool Databaza::setZobrazParam(std::vector<std::string>& zParam)
{
	if (zParam.size() == 0)
	{
		return true;
	}
	else
	{
		//std::vector<std::string> inLower;
		//for (auto &nPar : zParam) // parametre da do lower case
		//{
		//	std::string temp = "";
		//	std::locale loc;
		//	for (int i = 0; i < nPar.length(); ++i)
		//	{
		//		temp += std::tolower(nPar.at(i), loc);
		//	}
		//	inLower.push_back(temp);
		//}

		std::vector<std::string> m_paramToLow;
		for (auto &vsP : m_parametre)
		{
			m_paramToLow.push_back(toMalePismena(vsP));
		}
		if (zParam.front().compare("vsetko") == 0)
		{
			m_zobrazovanePar.clear();
			for (auto &p : m_parametre)
			{
				m_zobrazovanePar.push_back(p);
			}
			return true;
		}
		if (zParam.front().compare("vybratych") == 0)
		{
			vypisVyber();
			zParam.erase(zParam.begin());
		}
		else if (zParam.front().compare("vsetkych") == 0)
		{
			vypisVsetkych();
			zParam.erase(zParam.begin());
		}
		if (zParam.size() == 0)
		{
			return true;
		}
		for (auto& nPar : zParam) //testovanie ci sa zvoleny parameter nachadza medzi udajmi databazy
		{
			bool testNajdenia = false;
			int pocetNajdeni = 0;
			for (auto &vsP : m_paramToLow)
			{
				if (vsP.compare(nPar) == 0)
				{
					testNajdenia = true;
					break;
				}
			}
			if (!testNajdenia)
			{
				std::cout << "Zadali ste nespravny parameter!" << std::endl;
				return false;
			}
		}

		for (auto &vsP : m_paramToLow)
		{
			int pocetNajdeni = 0;
			for (auto &nPar : zParam)
			{
				if (vsP.compare(nPar) == 0)
				{
					++pocetNajdeni;
				}
			}
			if (pocetNajdeni > 1)
			{
				std::cout << "Zadali ste rovnake parametre!" << std::endl;
				return false;
			}
		}
		m_zobrazovanePar.clear();


		for (auto& nPar : zParam) //testovanie ci sa zvoleny parameter nachadza medzi udajmi databazy
		{
			for (auto &vsP : m_parametre)
			{
				std::string toLowVsp = toMalePismena(vsP);
				if (toLowVsp.compare(nPar) == 0)
				{
					m_zobrazovanePar.push_back(vsP);
				}
			}
		}
		return true;
	}
}

std::vector<std::string> Databaza::getM_Parametre()
{
	std::vector<std::string> temp;
	for (auto &p : m_parametre)
	{
		temp.push_back(p);
	}
	return temp;
}

Databaza::~Databaza()
{
}
