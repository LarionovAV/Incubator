#pragma once

#ifndef _ICONTROLENV
#define _ICONTROLENV


class ICheckEnvironment {
public:
	virtual int CheckParametr() = 0;
};
class IChangeEnvironment {
public:
	virtual void ChangeParametr() = 0;
};
#endif // !_ICONTROLENV