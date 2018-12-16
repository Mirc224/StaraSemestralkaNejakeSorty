#pragma once
#include <map>
#include "Udaj.h"
class PrvokDatabazy
{
public:
	PrvokDatabazy();
	virtual std::map<std::string, Udaj*>& getUdaje() = 0;
	virtual ~PrvokDatabazy();
};

