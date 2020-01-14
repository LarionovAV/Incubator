/*
	 лассы €иц
*/

#pragma once

#ifndef __EGG
#define __EGG


class Egg {
protected:
	int size;
	int weight;
	int hp = 100;
	int incubationPeriod;
	int timeToBirth;
	int optimalTemperature;
	int optimalWet;
public:
	int getSize() { return size; }
	int getWeight() { return weight; }
	int getHP() { return hp; }
	int getIncubationPeriod() { return incubationPeriod; }
	int getTimeToBirth() { return timeToBirth; }
	int getOptimalTemperature() { return optimalTemperature; }
	int getOptimalWet() { return optimalWet; }
};
class HenEgg : public Egg{
public:
	HenEgg(){
		size = 5;
		weight = 58;
		incubationPeriod = timeToBirth = 21;
		optimalTemperature = 38;
		optimalWet = 50;
	}
};
class DuckEgg : public Egg {
public:
	DuckEgg() {
		size = 7;
		weight = 80;
		incubationPeriod = timeToBirth = 27;
		optimalTemperature = 37;
		optimalWet = 50;
	}
};
class TurkeyEgg : public Egg {
public:
	TurkeyEgg() {
		size = 8;
		weight = 85;
		incubationPeriod = timeToBirth = 28;
		optimalTemperature = 37;
		optimalWet = 50;
	}
};
#endif // !__EGG