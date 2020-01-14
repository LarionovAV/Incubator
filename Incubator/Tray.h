/*
	 лассы лотков дл€ €иц
*/
#pragma once
#include "Egg.h"
#include <vector>
#include <iostream>
#include "Iterator.h"

using namespace std;

#ifndef __TRAY
#define __TRAY



class Slot {
protected:
	int weight;
	int size;
	vector <Slot*> slots;
	friend class SlotIterator;
public:
	virtual bool AddEgg(Egg*) = 0;
	virtual bool DeleteEgg(Egg*) = 0;
	virtual int getSize() = 0;
	virtual int getWeight() = 0;
	virtual int GetSlotsSize() = 0;
	virtual Slot* GetSlot(int) = 0;
	virtual void Display();

	static bool Compirer(Slot*, Slot*);
};
class Tray : public Slot{
protected:
	int maxWeight;
	
public:
	Tray(int maxw);
	~Tray();
	
	int GetSlotsSize();
	Slot* GetSlot(int index);
	void AddSlot(Slot* slot);
	bool AddEgg(Egg* ne);
	bool DeleteEgg(Egg* de);

	int getWeight();
	int getSize();

	IIterator<Slot*>* CreateIterator();
	
};
class SingleEggSlot : public Slot{
	Egg* egg;
public: 
	SingleEggSlot();
	SingleEggSlot(int s);
	SingleEggSlot(Egg* e);
	~SingleEggSlot() {}

	int GetSlotsSize();
	Slot* GetSlot(int index);
	bool AddEgg(Egg* ne);
	bool DeleteEgg(Egg* de);

	int getWeight();
	int getSize();
};


#endif // !__TRAY
