#ifndef COMBATANT_HPP
#define COMBATANT_HPP

#include "PimplMacro/PimplMacro.hpp"

enum class CombatantState{
     Idle
    ,Preparing
    ,Attacking
    ,Guarding
};

class Condition;

class Combatant{
public:
    Combatant();
    ~Combatant();

    void            TakeDamage(int amount);
    void            RecoverHealth(int amount);
    void            UseMana(double amount);
    void            GainMana(double amount);
    void            SetState(CombatantState);
	void            GainCondition(Condition&);
    //virtual void    UseSkill(Combatant& target);
    int             Hp() const;
    int             MaxHp() const;
    int             Mana() const;
    int             MaxMana() const;
    CombatantState  State() const;
private:
    HAS_PRIVATE_VARIABLES;
};

#endif

