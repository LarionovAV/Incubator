#pragma once

#include "IControlEnvironment.h"
#include "Environment.h"

#include <iostream>

#ifndef __CONTROLENV
#define __CONTROLENV

using namespace std;

class ChangeWet : public IChangeEnvironment {
public:
	ChangeWet() {}
	~ChangeWet() {}
	void ChangeParametr() { 
		cout << "I changed internal temperature" << endl; 
	}
};

class ChangeTenperature : public IChangeEnvironment {
public:
	ChangeTenperature() {}
	~ChangeTenperature() {}
	void ChangeParametr() {
		cout << "I changed internal temperature" << endl;
	}
};

class CheckWet : public ICheckEnvironment {
public:
	int CheckParametr() {
		cout << "I returned wet status" << endl;
		return  ExternalEnvironment::getInstance()->getWet();
	}
};

class CheckTenperature : public ICheckEnvironment {
public:
	int CheckParametr() {
		cout << "I returned temprature status" << endl;
		return ExternalEnvironment::getInstance()->getWet();
	}
};

#endif