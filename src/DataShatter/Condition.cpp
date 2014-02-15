#include "Condition.hpp"
#include "Combatant.hpp"

PRIVATE_VARIABLES(Condition){
    PrivateVariables(ConditionType type,
                     std::function<void(Combatant&, Combatant&, int&)> activate)
        : type(type)
        , activate(activate)
    {}
    ConditionType   type;
    std::function<void(Combatant&, Combatant&, int&)> activate;
};

Condition::Condition(ConditionType type,
                     std::function<void(Combatant&, Combatant&, int&)> activate)
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

