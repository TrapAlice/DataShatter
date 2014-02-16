#include "Enemy.hpp"
#include "GlobalTime.hpp"

PRIVATE_VARIABLES(Enemy){
	unsigned        preparingTime = -1;
	unsigned        damageTime = -1;
};

Enemy::Enemy()
	: INIT_PRIVATE_VARIABLES()
{}

Enemy::~Enemy(){}

void Enemy::Attack(Combatant& target)
{
    SetState(CombatantState::Preparing);
    m->preparingTime = GlobalTime::Current() + 500;
}

void Enemy::Update(Combatant& target)
{
	if( Mana() >= 25 && State() == CombatantState::Idle ){
		Attack(target);
		UseMana(25);
	}
	GainMana(0.1);
	if( GlobalTime::Current() > m->preparingTime && State() == CombatantState::Preparing){
		m->damageTime = GlobalTime::Current() + 1000;
		SetState(CombatantState::Attacking);
	}
	if( GlobalTime::Current() > m->damageTime && State() == CombatantState::Attacking ){
		target.TakeDamage(5);
		SetState(CombatantState::Idle);
	}
}

