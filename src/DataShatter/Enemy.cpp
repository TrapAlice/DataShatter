#include "Enemy.hpp"
#include "GlobalTime.hpp"

PRIVATE_VARIABLES(Enemy){
	unsigned        damageTime;
};

Enemy::Enemy()
	: INIT_PRIVATE_VARIABLES()
{}

Enemy::~Enemy(){}

void Enemy::Attack(Combatant& target)
{
    SetState(CombatantState::Attacking);
    m->damageTime = GlobalTime::Current() + 1;
    UseMana(20);
}

void Enemy::Update(Combatant& target)
{
	if( GlobalTime::Current() < m->damageTime ) return;
	target.TakeDamage(5);
}

