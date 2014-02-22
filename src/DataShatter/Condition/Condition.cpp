#include "Condition.hpp"
#include "Combatant.hpp"
#include "GlobalTime.hpp"
#include "ConditionData.hpp"
#include <memory>

PRIVATE_VARIABLES(Condition){
    PrivateVariables(ConditionData const& data)
        : data(data)
	, expireTime(GlobalTime::Current() + data.Duration())
    {}
    ConditionData const& data;
    unsigned        expireTime;
};

Condition::Condition(ConditionData const& data)
    : INIT_PRIVATE_VARIABLES(data)
{}

Condition::Condition(Condition& c)
	: INIT_PRIVATE_VARIABLES(c.m->data)
{
	m->expireTime = c.m->expireTime;
}

Condition::Condition(Condition&& c) noexcept
	: INIT_PRIVATE_VARIABLES(c.m->data)
{
	m->expireTime = c.m->expireTime;
}

Condition::~Condition() noexcept
{}

void Condition::Activate(Combatant& attacker, Combatant& defender, int& value)
{
	m->data.Activate(attacker, defender, value);
}

ConditionType Condition::Type() const { return m->data.Type(); }
bool Condition::isExpired() const { return m->expireTime <= GlobalTime::Current(); }

