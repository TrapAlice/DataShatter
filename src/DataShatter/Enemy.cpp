#include "Enemy.hpp"

PRIVATE_VARIABLES(Enemy){
};

Enemy::Enemy()
	: INIT_PRIVATE_VARIABLES()
{}

Enemy::~Enemy(){}

void Enemy::Attack(Combatant& target)
{
    target.TakeDamage(5);
    UseMana(20);
}

