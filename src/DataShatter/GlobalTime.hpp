#ifndef GLOBALTIME_HPP
#define GLOBALTIME_HPP

#include "PimplMacro/PimplMacro.hpp"
#include "common.hpp"

class GlobalTime{
public:
	static unsigned long Current();
	~GlobalTime();

	static void     SetDebugging();
	static void     Reset();
	static void     SetTime(unsigned value);
private:
	GlobalTime();
	static GlobalTime& getInstance();
	static unique_ptr<GlobalTime> timeInstance;
	HAS_PRIVATE_VARIABLES;
};

#endif

