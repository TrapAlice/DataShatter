#include "Condition.hpp"
#include "Combatant.hpp"
#include "GlobalTime.hpp"
#include <memory>

PRIVATE_VARIABLES(Condition){
    PrivateVariables(ConditionType type,
                     active_function activate,
		     unsigned duration)
        : type(type)
	, duration(duration)
	, expireTime(GlobalTime::Current() + duration)
        , activate(activate)
    {}
    ConditionType   type;
    unsigned        duration;
    unsigned        expireTime;
    active_function activate;
};

Condition::Condition(ConditionType type,
                     active_function activate,
		     unsigned duration)
    : INIT_PRIVATE_VARIABLES(type, activate, duration)
{}

Condition::Condition(Condition& c)
	: INIT_PRIVATE_VARIABLES(c.m->type, c.m->activate, c.m->duration)
{}

Condition::Condition(Condition&& c) noexcept
	: INIT_PRIVATE_VARIABLES(c.m->type, c.m->activate, c.m->duration)
{}

Condition::~Condition() noexcept
{}

void Condition::Activate(Combatant& attacker, Combatant& defender, int& value)
{
	m->activate(attacker, defender, value);
}

ConditionType Condition::Type() const { return m->type; }
bool Condition::isExpired() const { return m->expireTime <= GlobalTime::Current(); }

