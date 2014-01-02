#include "Character.hpp"

struct Character::PrivateVariables{
	int             hp = 50;
	int             maxHp = 50;
	double          mana = 25;
	double          maxMana = 25;
	double          heat = 0;
};

Character::Character(){}
Character::~Character(){}

void Character::TakeDamage(int amount)
{
	m->hp -= (m->hp - amount > 0)? amount : m->hp;
}

void Character::RecoverHealth(int amount)
{
	m->hp = (m->hp + amount > m->maxHp)? m->maxHp : m->hp + amount;
}

void Character::UseMana(double amount)
{
	m->mana -= (m->mana - amount > 0)? amount : m->mana;
}

void Character::GainMana(double amount)
{
	m->mana = (m->mana + amount > m->maxMana)? m->maxMana : m->mana + amount;
}

void Character::LoseHeat(double amount)
{
	m->heat -= (m->heat - amount > 0)? amount : m->heat;
}

void Character::GenerateHeat(double amount)
{
	m->heat = (m->heat + amount > 100)? 100 : m->heat + amount;
}

int Character::Hp() const { return m->hp; }
int Character::MaxHp() const { return m->maxHp; }
int Character::Mana() const { return m->mana; }
int Character::MaxMana() const { return m->maxMana; }
int Character::Heat() const { return m->heat; }

