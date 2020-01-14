#include "pch.h"
#include "Factory.h"
#include "Device.h"

Analizator* WetFactory::CreateAnalizator() {
	return new WetAnalizator();
}

Regulator* WetFactory::CreateRegulator() {
	return new WetRegulator();
}

Analizator* TemperatureFactory::CreateAnalizator() {
	return new TemperatureAnalizator();
}

Regulator* TemperatureFactory::CreateRegulator() {
	return new TemperatureRegulator();
}