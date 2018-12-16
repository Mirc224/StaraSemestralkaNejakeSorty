#pragma once
#include <iostream>
#include <string>
class Udaj
{
public:
	Udaj(std::string nazov);
	virtual void vypis() const;
	virtual std::string getValue() const;
	std::string getNazov() const { return m_nazov; }
	Udaj getUdaj() { 
		return *this; }
	virtual ~Udaj();
private:
	std::string m_nazov;
};
