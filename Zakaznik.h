#pragma once
#include <iostream>
#include <vector>
#include "Udaj.h"
#include <map>
#include "PrvokDatabazy.h"

class IdentifikacneCislo : public Udaj 
{
public:
	static int GPorCis;
	IdentifikacneCislo();
	IdentifikacneCislo(std::string par);
	void vypis() const override { std::cout << poradoveCisloZ; }
	std::string getValue() const override {
		std::string temp = std::to_string(poradoveCisloZ);
		return temp; }
	virtual ~IdentifikacneCislo();
private:
	int poradoveCisloZ;
};

class Meno : public Udaj
{
public:
	Meno(std::string meno);
	Meno();
	void vypis() const override  { std::cout << m_meno; }
	std::string getValue() const override { return m_meno; }
	virtual ~Meno();
private:
	std::string m_meno;
};

class Priezvisko : public Udaj
{
public:
	Priezvisko(std::string priezvisko);
	Priezvisko();
	void vypis() const override { std::cout << m_priezvisko; }
	std::string getValue() const override { return m_priezvisko; }
	virtual ~Priezvisko();
private:
	std::string m_priezvisko;
};

class PSC : public Udaj
{
public:
	PSC(std::string PSC);
	PSC();
	void vypis() const override  { std::cout << m_PSC; }
	std::string getValue() const override { return m_PSC; }
	virtual ~PSC();
private:
	std::string m_PSC;
};


class Zakaznik : public PrvokDatabazy
{
public:
	Zakaznik(std::string meno, std::string priezvisko, std::string PSC);
	std::map<std::string, Udaj*>& getUdaje();
	virtual ~Zakaznik();
private:
	std::map<std::string, Udaj*> m_udaje;
};

