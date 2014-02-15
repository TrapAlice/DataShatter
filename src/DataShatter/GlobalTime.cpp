#include "GlobalTime.hpp"
#include "libtcod.hpp"

PRIVATE_VARIABLES(GlobalTime){
	PrivateVariables()
		: start(Time::now())
		, testing(false)
		, testTime(0)
	{}
	TimePoint   start;
	bool        testing;
	unsigned long testTime;
};

unsigned long GlobalTime::Current()
{
	if( getInstance().m->testing ) return getInstance().m->testTime;
	auto delta = Time::now() - getInstance().m->start;
	return delta.count()/1000000;
}

void GlobalTime::SetDebugging()
{
	getInstance().m->testing = true;
}

void GlobalTime::Reset()
{
	getInstance().m->testTime = 0;
}

void GlobalTime::SetTime(unsigned value)
{
	getInstance().m->testTime = value;
}

GlobalTime& GlobalTime::getInstance()
{
	if( !timeInstance ){
		timeInstance.reset(new GlobalTime());
	}
	return *timeInstance.get();
}

unique_ptr<GlobalTime> GlobalTime::timeInstance;

GlobalTime::GlobalTime()
	: INIT_PRIVATE_VARIABLES()
{
}

GlobalTime::~GlobalTime(){}

