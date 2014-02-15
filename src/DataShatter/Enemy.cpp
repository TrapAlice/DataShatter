#include "Enemy.hpp"
#include "GlobalTime.hpp"

PRIVATE_VARIABLES(Enemy){
	unsigned        damageTime = -1;
};

Enemy::Enemy()
	: INIT_PRIVATE_VARIABLES()
{}

Enemy::~Enemy(){}

void Enemy::Attack(Combatant& target)
{
    SetState(CombatantState::Attacking);
    m->damageTime = GlobalTime::Current() + 1000;
    DEBUG(GlobalTime::Current() << " < " << m->damageTime);
}

void Enemy::Update(Combatant& target)
{
	if( Mana() >= 25 && State() == CombatantState::Idle ){
		Attack(target);
		UseMana(25);
	}
	GainMana(0.1);
	if( GlobalTime::Current() > m->damageTime && State() == CombatantState::Attacking ){
		DEBUG("Enemy attacks!");
		target.TakeDamage(5);
		SetState(CombatantState::Idle);
	}
}

