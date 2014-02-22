#include "Combatant.hpp"
#include "common.hpp"
#include "Condition/Condition.hpp"

PRIVATE_VARIABLES(Combatant){
    int             hp = 50;
    int             maxHp = 50;
    double          mana = 25;
    double          maxMana = 25;
    CombatantState  state = CombatantState::Idle;
	std::list<Condition> conditions;
};

Combatant::Combatant()
    : INIT_PRIVATE_VARIABLES()
{}

Combatant::~Combatant(){}

void Combatant::TakeDamage(int amount)
{
	for( auto& condition :  m->conditions ){
		if( condition.Type() == ConditionType::On_defense){
			condition.Activate(*this, *this, amount);
		}
	}
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

void Combatant::SetState(CombatantState newState)
{
    m->state = newState;
}

void Combatant::GainCondition(Condition& newCondition)
{
	m->conditions.emplace_back(newCondition);
}

std::list<Condition>& Combatant::Conditions() const { return m->conditions; }

int Combatant::Hp() const { return m->hp; }
int Combatant::MaxHp() const { return m->maxHp; }
int Combatant::Mana() const { return m->mana; }
int Combatant::MaxMana() const { return m->maxMana; }
CombatantState Combatant::State() const { return m->state; }

