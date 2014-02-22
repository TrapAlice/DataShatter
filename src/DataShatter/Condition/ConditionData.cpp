#include "ConditionData.hpp"

PRIVATE_VARIABLES(ConditionData){
	PrivateVariables(ConditionType type,
			 unsigned duration,
			 active_function activate)
		: type(type)
		, duration(duration)
		, activate(activate)
	{}
	ConditionType   type;
	unsigned        duration;
	active_function activate;
};

ConditionData::ConditionData(ConditionType type,
			     unsigned duration,
			     active_function activate)
	: INIT_PRIVATE_VARIABLES(type, duration, activate)
{}

ConditionData::ConditionData(ConditionData &c)
	: INIT_PRIVATE_VARIABLES(c.m->type, c.m->duration, c.m->activate)
{}

ConditionData::~ConditionData(){}

void ConditionData::Activate(Combatant& attacker, Combatant& defender, int& value) const
{
	m->activate(attacker, defender, value);
}

ConditionType ConditionData::Type() const { return m->type; }
unsigned ConditionData::Duration() const { return m->duration; }

ConditionData const Guarding{ConditionType::On_defense, 250,
	[](Combatant&, Combatant&, int& damage){
		damage = 0;
	}};
