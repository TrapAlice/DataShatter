#include "Condition.hpp"
#include "Combatant.hpp"

PRIVATE_VARIABLES(Condition){
    PrivateVariables(ConditionType type,
                     active_function activate)
        : type(type)
        , activate(activate)
    {}
    ConditionType   type;
    int             expire_time;
    active_function activate;
};

Condition::Condition(ConditionType type,
                     active_function activate)
    : INIT_PRIVATE_VARIABLES(type, activate)
{}

Condition::Condition(Condition&& c) noexcept
	: INIT_PRIVATE_VARIABLES(c.m->type, c.m->activate)
{}

Condition::~Condition() noexcept
{}

void Condition::Activate(Combatant& attacker, Combatant& defender, int& value)
{
	m->activate(attacker, defender, value);
}

ConditionType Condition::Type() const { return m->type; }
bool Condition::isExpired() const { return false; }

