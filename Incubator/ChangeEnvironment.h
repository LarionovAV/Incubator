#pragma once

#include "IChangeEnvironment.h"
#include <iostream>

using namespace std;

#ifndef __CHANGEENV
#define __CHANGEENV



class RandomChange : public IChangeParametr {
public:
	int ChangeParametr(int currentP) {
		cout << "I changed this parametr randomly" << endl;
		return currentP;
	}
	RandomChange() {}
	~RandomChange() {}
};

class DirectedChange : public IChangeParametr {
protected:
	int difference;
public:
	int ChangeParametr(int currentP) {
		cout << "I changed this parametr on " << difference << " points" << endl;
		return currentP + difference;
	}
	DirectedChange() {}
	DirectedChange(int dp) { 
		difference = dp; 
	}
	~DirectedChange() {}
};
#endif // !__CHANGEENV