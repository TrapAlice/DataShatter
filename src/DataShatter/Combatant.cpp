#include "Combatant.hpp"

PRIVATE_VARIABLES(Combatant){
    int             hp = 50;
    int             maxHp = 50;
    double          mana = 25;
    double          maxMana = 25;
};

Combatant::Combatant()
    : INIT_PRIVATE_VARIABLES()
{}

Combatant::~Combatant(){}

void Combatant::TakeDamage(int amount)
{
    m->hp -= (m->hp - amount > 0)? amount : m->hp;
}

void Combatant::RecoverHealth(int amount)
{
    m->hp = (m->hp + amount > m->maxHp)? m->maxHp : m->hp + amount;
}

void Combatant::UseMana(double amount)
{
    m->mana -= (m->mana - amount > 0)? amount : m->mana;
}

void Combatant::GainMana(double amount)
{
    m->mana = (m->mana + amount > m->maxMana)? m->maxMana : m->mana + amount;
}

int Combatant::Hp() const { return m->hp; }
int Combatant::MaxHp() const { return m->maxHp; }
int Combatant::Mana() const { return m->mana; }
int Combatant::MaxMana() const { return m->maxMana; }

