#include "pch.h"
#include "Environment.h"
ExternalEnvironment* ExternalEnvironment::Instance = 0;
char ExternalEnvironment::season = 0;


void Environment::ChangeEnvironment() {
}

Temperature::Temperature(int t, TemperatureAnalizator* ta) {
	em = new EventManager(ta);
}

Wet::Wet(int w, WetAnalizator* wa) : Wet(w){
	em = new EventManager(wa);
}

void Parametr::ChangeParametr() {
//	icp->ChangeParametr(value);
	em->Notify(this);
}