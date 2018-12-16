#pragma once
#include "Udaj.h"
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <map>
class Databaza
{
public:
	Databaza();
	void setParametre(std::vector<Udaj>& parametre);
	void vypisHlavicku();
	virtual void vypisZaznam() = 0;
	virtual void vypisVyber() = 0;
	virtual void vypisVsetkych() = 0;
	virtual void refresh() = 0;
	//bool pridavanie();
	bool setZobrazParam(std::vector<std::string>& zParam);
	virtual bool hladaj() = 0;
	std::vector<std::string>& getZobParametre() { return m_zobrazovanePar; }
	virtual bool pridajDoDatabazy() = 0;
	virtual bool vyber() = 0;
	virtual bool vycistiVyber() = 0;
	std::vector<std::string> getM_Parametre();
	int getM_parametreSize() const { return m_parametre.size(); }
	virtual bool odstranZDatabazy() = 0;
	//virtual std::vector<std::string>& getZoznamUdajov() = 0;
	//void zorad();
	virtual ~Databaza();
private:
	std::vector<std::string> m_parametre;
	std::vector<std::string> m_zobrazovanePar;
};

