#pragma once
#include <vector>
using namespace std;
#ifndef __ITERATOR
#define __ITERATOR

template <typename T>
class IIterator {
public:
	virtual T Next() = 0;
	virtual bool HasNext() = 0;
	virtual vector<T> SortCollection() = 0;
};
#endif 