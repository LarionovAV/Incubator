#pragma once

#ifndef __FACTORY
#define __FACTORY

class AbstractFactory {
public:
	virtual Analizator* CreateAnalizator() = 0;
	virtual Regulator* CreateRegulator() = 0;
};

class WetFactory : public AbstractFactory {
public:
	Analizator* CreateAnalizator();
	Regulator* CreateRegulator();
};

class TemperatureFactory : public AbstractFactory {
public:
	Analizator* CreateAnalizator();

	Regulator* CreateRegulator();
};

#endif // !__FACTORY