#ifndef COMBATANT_HPP
#define COMBATANT_HPP

#include "PimplMacro/PimplMacro.hpp"

class Combatant{
public:
    Combatant();
    ~Combatant();

    void            TakeDamage(int amount);
    void            RecoverHealth(int amount);
    void            UseMana(double amount);
    void            GainMana(double amount);
    //virtual void    UseSkill(Combatant& target);
    int             Hp() const;
    int             MaxHp() const;
    int             Mana() const;
    int             MaxMana() const;
private:
    HAS_PRIVATE_VARIABLES;
};

#endif

