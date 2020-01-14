#pragma once


#include "Tray.h"
#include "Environment.h"
#include "Device.h"
#include <vector>

#ifndef __INCUBATOR
#define __INCUBATOR

class Incubator {
protected:
	int maxTraysCount;
	int traysCount;
	Tray** trays;
	Environment* internalEnvironment;
	Device* wAnalizator;
	Device* tAnalizator;
	Device* wRegulator;
	Device* tRegulator;

public:
	Incubator() {
		wAnalizator = wRegulator = tAnalizator = tRegulator = nullptr;
		internalEnvironment = new Environment();
	}
	Incubator(int maxTCount) {
		traysCount = 0;
		maxTraysCount = maxTCount;
		trays = new Tray*[maxTraysCount];
		internalEnvironment = new Environment();
		wAnalizator = new WetAnalizator();
		tAnalizator = new TemperatureAnalizator();
		wRegulator = new WetRegulator();
		tRegulator = new TemperatureRegulator();
	}
	~Incubator() {
		delete[] trays;
		delete internalEnvironment;
	}
	void AddTray(Tray* nt) {
		trays[traysCount++] = nt;
	}

	void SetWetAnalizator(Device *wa) {
		if (wAnalizator != nullptr)
			delete wAnalizator;
		wAnalizator = (Device*)wa;
		wAnalizator->SetOwner(this);
	}
	void SetTempAnalizator(Device *ta) {
		if (tAnalizator != nullptr)
			delete wAnalizator;
		tAnalizator = (Device*)ta;
		tAnalizator->SetOwner(this);
	}
	void SetWetRegulator(Device *wr) {
		if (wRegulator != nullptr)
			delete wAnalizator;
		wRegulator = (Device*)wr;
		wRegulator->SetOwner(this);
	}
	void SetTempRegulator(Device *tr) {
		if (tRegulator != nullptr)
			delete wAnalizator;
		tRegulator = (Device*)tr;
		tRegulator->SetOwner(this);
	}
	Device* GetWetRegulator() {
		return wRegulator;
	}
	Device* GetWetAnalizator() {
		return wAnalizator;
	}
	Device* GetTemperatureRegulator() {
		return tRegulator;
	}
	void PrintInfo() {
		cout << "\t>>Wet analizator<<" << endl;
		wAnalizator->PrintInfo();
		cout << "\t>>Wet regulator<<" << endl;
		wRegulator->PrintInfo();
		cout << "\t>>Temperature analizator<<" << endl;
		tAnalizator->PrintInfo();
		cout << "\t>>Tenperature regulator<<" << endl;
		tRegulator->PrintInfo();
	}
};


#endif // !__INCUBATOR