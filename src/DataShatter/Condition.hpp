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
	using active_function = std::function<void(Combatant&, Combatant&, int&)>;
    Condition(ConditionType, active_function);
	Condition(Condition&&) noexcept;
    ~Condition() noexcept;

	ConditionType   Type() const;
	void            Activate(Combatant&, Combatant&, int&);
	bool            isExpired() const;
private:
    HAS_PRIVATE_VARIABLES;
};

#endif
