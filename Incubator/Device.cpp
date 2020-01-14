#include "pch.h"
#include "Environment.h"
#include "Incubator.h"
void StateOn::DoAction() {
	cout << "I'm working" << endl;
}
void StateOff::DoAction() {
	cout << "I'm off" << endl;
}
void StateBroken::DoAction() {
	cout << "I'm broken" << endl;
}

void Device::ChangeStatement(int ns){
		delete statement;
		switch (ns) {
		case DEVICE_ON:
			statement = new StateOn(this);
			break;
		case DEVICE_OFF:
			statement = new StateOff(this);
			break;
		case DEVICE_BROKEN:
			statement = new StateBroken(this);
			break;
		default: 
			cout << "Unknown state" << endl;
		}
		

}
void Device::ChangeStatement(Statement* ns) {
	delete statement;
	statement = ns;
}
void Device::SetPowCons(int pc) {
	powerConsumption = pc;
}
void Device::SetOwner(Incubator *inc) {
	owner = inc;
}
void Device::SetDesc(string desc) {
	description = desc;
}
string Device::getDescription() {
	return description;
}

Device* TemperatureRegulator::Clone() {
	return new TemperatureRegulator(powerConsumption, "I am clone.  ");
}
Device* WetRegulator::Clone() {
	return new WetRegulator(powerConsumption, "I am clone.  ");
}

int Analizator::CheckExternalEnvironment() {
	return chkEnv->CheckParametr();
}

Device* TemperatureAnalizator::Clone() {
	return new TemperatureAnalizator(powerConsumption, "I am clone.  ");
}
void TemperatureAnalizator::Update(Parametr *p) {
	cout << "I got temperature value" << endl;
}

Device* WetAnalizator::Clone() {
	return new WetAnalizator(powerConsumption, "I am clone.  ");
}
void WetAnalizator::Update(Parametr *p) {
	if (c != nullptr)
		delete c;
	if (p->getValue() < 60) {
		c = new CommandON((WetRegulator*)owner->GetWetRegulator());
		c->Execute();
	}
	else if (p->getValue() > 80) {
		c = new CommandOFF((WetRegulator*)owner->GetWetRegulator());
		c->Execute();
	}



}


Snapshot* Device::TakeSnapshot(){
	return new Snapshot(this, statement->Clone(), powerConsumption, description);
}



