#pragma once

#ifndef __PROTO
#define __PROTO
 
template <class T>
class IPrototype {
public:
	virtual T* Clone() = 0;
};
#endif