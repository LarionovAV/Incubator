#pragma once




#ifndef __DEVICE
#define __DEVICE
#include "ControlEnvironment.h"
#include <ctime>
#include <string>
#include "Prototype.h"

const int DEVICE_ON = 1;
const int DEVICE_OFF = 0;
const int DEVICE_BROKEN = -1;

class Device;
class Snapshot;
class Incubator;

class WorkingMode {
public:
	virtual void DoStrategy() = 0;
};
class SwitchInTime : public WorkingMode {
public:
	void DoStrategy() {
		cout << "Device On" << endl;
		cout << "Device working" << endl;
		cout << "Device working" << endl;
		cout << "Device working" << endl;
		cout << "Device Off" << endl;
	}
};
class NonStop : public WorkingMode {
	void DoStrategy() {
		cout << "Device working until it will be stoped" << endl;
	}
};

class Statement : public IPrototype<Statement> {
public:
	virtual void DoAction() = 0;
	virtual Statement* Clone() = 0;
};

class StateOn : public Statement{
private:
	Device* dev;
public:
	StateOn(Device* d) {
		dev = d;
	}
	void DoAction();
	Statement* Clone() {
		return new StateOn(dev);
	}
};
class StateOff : public Statement {
private:
	Device* dev;
	
public:
	StateOff(Device* d) {
		dev = d;
	}
	void DoAction();
	Statement* Clone() {
		return new StateOff(dev);
	}
};
class StateBroken : public Statement {
private:
	Device* dev;
public:
	StateBroken(Device* d) {
		dev = d;
	}
	void DoAction();
	Statement* Clone() {
		return new StateBroken(dev);
	}
};


class Device : IPrototype<Device>{
protected:
	Statement* statement;
	int powerConsumption;
	string description;
	Incubator* owner;
public:
	Device() {
		statement = new StateOff(this);
		powerConsumption = 1;
	}
	Device(int pc) : Device(){
		powerConsumption = pc;
	}
	Device(int pc, string desc) : Device(pc) {
		powerConsumption = pc;
		description = desc;
	}
	~Device() {}

	void ChangeStatement(int);
	void ChangeStatement(Statement*);
	void SetPowCons(int);
	void SetOwner(Incubator*);
	void SetDesc(string desc);
	string getDescription();
	
	virtual void DoAction() {
		statement->DoAction();
	};
	virtual Snapshot* TakeSnapshot();
	virtual Device* Clone() = 0;
	virtual void PrintInfo() {
		cout << description << endl;
	};
};

class Regulator : public Device
 {
 protected:
	 IChangeEnvironment *chEnv;
	 WorkingMode* wm;
public:	
	Regulator() {}
	Regulator(WorkingMode* workMode) {
		wm = workMode;
	}
	Regulator(int pc, string desc) : Device(pc, desc) {}
	~Regulator() {}

	/*void DoAction() {
		chEnv->ChangeParametr();
	}*/
	virtual void DoAction() {
		wm->DoStrategy();
	}
	virtual Device* Clone() = 0;

	void SetMode(WorkingMode* wm) {
		this->wm = wm;
	}
};
class TemperatureRegulator : public Regulator {
public:
	TemperatureRegulator() {
		chEnv = new ChangeTenperature();
		description = "TEMPregulator";
	}
	TemperatureRegulator(WorkingMode* wm) : Regulator(wm){}
	TemperatureRegulator(int pc, string desc) : Regulator(pc, desc) {
		chEnv = new ChangeTenperature();
		description = "TEMPregulator";
	}
	~TemperatureRegulator() {
		delete chEnv;
	}

	Device* Clone();
};
class WetRegulator : public Regulator {
protected:
	int WaterReserve;
public:
	WetRegulator() { 
		WaterReserve = 100; 
		chEnv = new ChangeWet();
		description = "WETregulator";
	}
	WetRegulator(WorkingMode* wm) : Regulator(wm) {}
	WetRegulator(int pc, string desc) : Regulator(pc, desc) {
		WaterReserve = 100;
		chEnv = new ChangeWet();
		description = "WETregulator";
	}
	~WetRegulator() {
		delete chEnv;
	}

	void DoAction() {
		cout << "I Change Wet" << endl;
	}
	Device* Clone();
};

class Command {
protected:
	Regulator* r;
public:
	virtual void Execute() = 0;
};
class CommandON : public Command {
public:
	CommandON(Regulator* reg) {
		r = reg;
	}
	void Execute() {
		r->ChangeStatement(new StateOn(r));
		cout << "Regulator ON" << endl;
	}
};
class CommandOFF : public Command {
public:
	CommandOFF(WetRegulator *reg) {
		r = reg;
	}
	void Execute() {
		r->ChangeStatement(new StateOff(r));
		cout << "Regulator OFF" << endl;
	}
};

class Analizator : public Device{
protected:
	ICheckEnvironment *chkEnv;
	Command *c;
public:
	Analizator(){}
	Analizator(int pc) : Device(pc) {
	}
	Analizator(int pc, string desc) : Device(pc, desc) {}
	~Analizator() {}
	/*void DoAction() {
		CheckExternalEnvironment();
	}*/

	int CheckExternalEnvironment();
	void SetCommand(Command* com) {
		c = com;
	}
	virtual Device* Clone() = 0;
	virtual void Update(Parametr* p) {
		cout << "I got value" << endl;
	};
};
class TemperatureAnalizator : public Analizator {
public:
	TemperatureAnalizator() {
		chkEnv = new CheckTenperature();
		description = "TEMPanalizator";
	}
	TemperatureAnalizator(int pc) :  Analizator(pc) {
		chkEnv = new CheckTenperature();
		description = "TEMPanalizator";
	}
	TemperatureAnalizator(int pc, string desc) : Analizator(pc, desc) {
		chkEnv = new CheckTenperature();
		description += "TEMPanalizator";
	}
	~TemperatureAnalizator() {
		delete chkEnv;
	}

	Device* Clone();

	void Update(Parametr *p);
};
class WetAnalizator : public Analizator {
public:
	WetAnalizator() {
		chkEnv = new CheckWet();
		description = "WETanalizator";
	}
	WetAnalizator(WetRegulator* wreg) {
	}
	WetAnalizator(int pc) : Analizator(pc) {
		chkEnv = new CheckTenperature();
		description = "WETanalizator";
	}
	WetAnalizator(int pc, string desc) : Analizator(pc, desc) {
		chkEnv = new CheckTenperature();
		description = "WETanalizator";
	}
	~WetAnalizator() {
		delete chkEnv;
	}

	Device* Clone();

	/*void DoAction() {
		cout << "I Change Wet" << endl;
	}*/
	void Update(Parametr *p);
};

class ProxyRegulator : public IChangeEnvironment{
private:
	Regulator *pRegulator;
public:
	ProxyRegulator(Regulator *pr) {
		pRegulator = pr;
	}
	~ProxyRegulator(){
		delete pRegulator;
	}
	void ChangeParametr() {
		cout << "I am Proxy!!! ";
		srand(time(0));
		if (rand() % 2)
			pRegulator->DoAction();
		else
			cout << "I don't gonna work. Go away" << endl;
	}
};

class Barometr {
private:
	int pressure = 755;
public:
	int ShowPressure() {
		cout << "I check pressure" << endl;
		return pressure;
	}


};
class Adapter : public ICheckEnvironment {
	Barometr *barometr;
public:
	int CheckParametr() {
		return barometr->ShowPressure();
	}
	Adapter(Barometr *bmtr) {
		barometr = bmtr;
	}
};

class ExtraFunction : public Device {
private:
	ExtraFunction() {}
protected:
	Device *decorated;
	ExtraFunction(Device* dec) {
		decorated = dec;
	}
	virtual void DoExtra() = 0;
	virtual void DoAction() {
		DoExtra();
		decorated->DoAction();
	}
public:
	/*virtual void DoAction() = 0;*/
	virtual Device* Clone() = 0;
	virtual void PrintInfo() {
		decorated->PrintInfo();
		cout << "\twith " << description << endl;
	}
};
class Lamp : public ExtraFunction {
public:
	void DoExtra() {
		cout << "I'm shining" << endl << "\t";
	}
	Lamp(Device* dev) : ExtraFunction(dev) {
		description = "Lamp";
	}
	Device* Clone() {
		return new Lamp(decorated);
	}
};
class Dinamic : public ExtraFunction {
public:
	void DoExtra() {
		cout << "I made some noise" << endl << "\t";
	}
	Dinamic(Device* dev) : ExtraFunction(dev) {
		description = "Dinamic";
	}
	Device* Clone() {
		return new Dinamic(decorated);
	}
};

class Snapshot {
private:
	Device* stored;
	int powerCons;
	Statement* state;
	string Descr;
public:
	Snapshot(Device* d, Statement* s, int pc, string desc) {
		stored = d;
		powerCons = pc;
		state = s;
		Descr = desc;
	}
	void Restore() {
		stored->ChangeStatement(state);
		stored->SetPowCons(powerCons);
		stored->SetDesc(Descr);
	}
};

class EventManager {
private:
	Analizator* listener  = nullptr;
public:
	EventManager(Analizator* a) {
		listener = a;
	}
	void SetListener(Analizator *a) {
		listener = a;
	}
	
	void ResetListener() {
		listener = nullptr;
	}

	void Notify(Parametr* p) {
		listener->Update(p);
	}
};


#endif // !__DEVICE