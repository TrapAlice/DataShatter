#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "PimplMacro/PimplMacro.hpp"
#include <functional>

class Combatant;
class ConditionData;
enum class ConditionType;

class Condition{
public:
    Condition(ConditionData const& data);
	Condition(Condition&);
	Condition(Condition&&) noexcept;
    ~Condition() noexcept;

	ConditionType   Type() const;
	void            Activate(Combatant&, Combatant&, int&);
	bool            isExpired() const;
private:
    HAS_PRIVATE_VARIABLES;
};

#endif

