#pragma once
#include "Tray.h"
#include <algorithm>

#ifndef __CONCITER
#define __CONCITER

class SlotIterator : public IIterator<Slot*> {
private:
	Tray* collection;
	vector<int> current;

	Slot* LevelUp() {
		current.pop_back();
		Slot* cur = collection;
		for (int i = 0; i < current.size() - 1; i++) {
			cur = cur->GetSlot(current[i]);
		}
		return cur;

	}
public:
	SlotIterator(Tray* collectionSource) {
		collection = collectionSource;
	}

	bool HasNext() {
		bool has = false;
		vector<int> tmp = current;
		if (Next() != nullptr) {
			has = true;
		}
		else {
			cout << "I have no next element!" << endl;
		}
		current = tmp;
		return has;
	}
	Slot* Next() {
		Slot* cur = collection;
		if (current.empty()) {
			while (cur->GetSlot(0) != nullptr) {
				cur = cur->GetSlot(0);
				current.push_back(0);
			}
		}
		else {

			for (int i = 0; i < current.size() - 1; i++) {
				cur = cur->GetSlot(current[i]);
			}
			while (current[current.size() - 1] >= cur->slots.size() - 1
				&& cur != collection) {
				cur = LevelUp();
			}
			if (cur == collection &&
				current[0] >= cur->slots.size() - 1) {
				return nullptr;
			}
			else {
				cur = cur->slots[++current[current.size() - 1]];
				while (cur->GetSlot(0 != nullptr)) {
					cur = cur->GetSlot(0);
					current.push_back(0);
				}	
			}
		}
		return cur;
	}

	vector<Slot*> SortCollection() {
		vector<Slot*> sorted;
		IIterator<Slot*> *it = collection->CreateIterator();
		while (it->HasNext()) {
			sorted.push_back(it->Next());
		}
		sort(sorted.begin(), sorted.end(), Slot::Compirer);
		return sorted;
	}
};
#endif // !__CONCITER