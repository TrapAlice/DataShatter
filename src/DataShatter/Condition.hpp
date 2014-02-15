#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "PimplMacro/PimplMacro.hpp"
#include <functional>

enum class ConditionType{
    On_turn,
    On_attack,
    On_defense
};

class Combatant;

class Condition{
public:
    Condition(ConditionType, std::function<void(Combatant&, Combatant&, int&)>);
	Condition(Condition&&) noexcept;
    ~Condition() noexcept;

	ConditionType   Type() const;
	void            Activate(Combatant&, Combatant&, int&);
private:
    HAS_PRIVATE_VARIABLES;
};

#endif

