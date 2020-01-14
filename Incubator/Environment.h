/*
	Классы для окружающей среды
*/
#pragma once



#ifndef __ENVIRONMENT
#define __ENVIRONMENT
#include "IChangeEnvironment.h"
class Environment;
class TemperatureAnalizator;
class WetAnalizator;
class EventManager;
const char SEASON_WINTER = 1;
const char SEASON_SPRING = 2;
const char SEASON_SUMMER = 3;
const char SEASON_FALL = 4;
class Parametr {
protected:
	int value;
	IChangeParametr *icp;
	EventManager* em;
public:
	Parametr() {}
	Parametr(int v) {
		value = v;
	}
	~Parametr() {}
	void setValue(int v) {
		value = v;
	}
	int getValue() {
		return value;
	}
	virtual void ChangeParametr();

	void ChangeICP(IChangeParametr *nicp) {
		if (icp != nullptr)
			delete icp;
		icp = nicp;
	}
};
class Temperature : public Parametr {
public:
	Temperature() {}
	Temperature(int t) : Parametr(t) {}
	Temperature(int, TemperatureAnalizator*);
	~Temperature() {}

};
class Wet : public Parametr {
public:
	Wet() {}
	Wet(int w) : Parametr(w) {}
	Wet(int w, WetAnalizator*);
	~Wet() {}
};

class EventManager;
class Environment {
protected:
	Parametr wet;
	Parametr temperature;
	
public:
	virtual void ChangeEnvironment();
	Environment() {
		temperature = 20;
		wet = 70;
	}
	Environment(int t, int w) {
		temperature = t;
		wet = w;
	}
	~Environment() {}
	int getWet() {
		return wet.getValue();
	}
	int getTemperature() {
		return temperature.getValue();
	}
};

class ExternalEnvironment : public Environment {
private:
	static char season;
	static ExternalEnvironment *Instance;
	ExternalEnvironment() : ExternalEnvironment(SEASON_SUMMER) {
	}
	ExternalEnvironment(char season) {
		this->season = (season - 1) % 4 + 1;
	}
public:

	static ExternalEnvironment* getInstance() {
		if (!Instance)
			Instance = new ExternalEnvironment();
		return Instance;
	}
	static ExternalEnvironment* getInstance(char season) {
		if (!Instance)
			Instance = new ExternalEnvironment(season);
		return Instance;
	}
	void changeEnvironment() {
		wet.ChangeParametr();
		temperature.ChangeParametr();
	}
	void changeSeason() {
		season = season % 4 + 1;
	}
	static void DisplaySeason() {
		switch (season)
		{
		case SEASON_SUMMER:
			cout << "Summer is now" << endl;
			break;
		case SEASON_WINTER:
			cout << "Winter is now" << endl;
			break;
		case SEASON_SPRING:
			cout << "Spring is now" << endl;
			break;
		case SEASON_FALL:
			cout << "Fall is now" << endl;
			break;
		default:
			break;
		}
	}
};







#endif // !__ENVIRONMENT

