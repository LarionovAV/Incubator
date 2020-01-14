#include "pch.h"
#include "Tray.h"
#include "ConcreteIterators.h"

void Slot::Display() {
	cout << "My weight = " << getWeight() << endl;
}
bool Slot::Compirer(Slot* s1, Slot* s2) {
	if (s1->getWeight() < s2->getWeight())
		return true;
	else
		return false;
}

Tray::Tray(int maxw) {
	maxWeight = maxw;

}
Tray::~Tray() {
	delete[] & slots;
}
int Tray::GetSlotsSize() {
	return slots.size();
};
Slot* Tray::GetSlot(int index) {
	if (slots.empty())
		return nullptr;
	return slots[index];
};
void Tray::AddSlot(Slot* slot) {
	if (slot->getWeight() <= maxWeight - getWeight()) {
		slots.push_back(slot);
	}
}
bool Tray::AddEgg(Egg* ne) {
	if (ne->getWeight() <= maxWeight - weight) {
		for (Slot* slot : slots)
		{
			if (slot->AddEgg(ne)) {
				weight += ne->getWeight();
				return true;
			}
		}
	}
	return false;
}
bool Tray::DeleteEgg(Egg* de) {
	for (Slot* slot : slots) {
		if (slot->DeleteEgg(de)) {
			weight -= de->getWeight();
			return true;
		}
	}

	return false;
}
int Tray::getWeight() {
	int w = 0;
	for (Slot* slot : slots) {
		w += slot->getWeight();
	}

	return w;
}
int Tray::getSize() { return 0; }
IIterator<Slot*>* Tray::CreateIterator() {
	return new SlotIterator(this);
}


SingleEggSlot::SingleEggSlot() {
	egg = nullptr;
	size = 20;
}
SingleEggSlot::SingleEggSlot(int s) : SingleEggSlot() {
	size = s;
}
SingleEggSlot::SingleEggSlot(Egg* e) {
	egg = e;
}
int SingleEggSlot::GetSlotsSize() {
	return 0;
}
Slot* SingleEggSlot::GetSlot(int index) {
	return nullptr;
}
bool SingleEggSlot::AddEgg(Egg* ne) {
	if (egg == nullptr && size >= ne->getSize()) {
		egg = ne;
		weight = ne->getWeight();
		return true;
	}
	else
		return false;
}
bool SingleEggSlot::DeleteEgg(Egg* de) {
	if (egg == de) {
		egg = nullptr;
		weight = 0;
		return true;
	}
	else
		return false;
}
int SingleEggSlot::getWeight() {
	return weight;
}
int SingleEggSlot::getSize() {
	return size;
}
