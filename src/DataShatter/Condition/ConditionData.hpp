#ifndef CONDITIONDATA_HPP
#define CONDITIONDATA_HPP

#include "PimplMacro/PimplMacro.hpp"

enum class ConditionType{
    On_tick,
    On_attack,
    On_defense
};

class Combatant;

class ConditionData{
public:
	using active_function = std::function<void(Combatant&, Combatant&, int&)>;
	ConditionData(ConditionType, unsigned duration, active_function);
	ConditionData(ConditionData&);
	~ConditionData();

	ConditionType   Type() const;
	unsigned        Duration() const;
	void            Activate(Combatant&, Combatant&, int&) const;
private:
	HAS_PRIVATE_VARIABLES;
};

extern ConditionData const Guarding;

#endif

