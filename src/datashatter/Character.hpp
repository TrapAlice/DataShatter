#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "common.hpp"

class Character{
public:
	Character();
	~Character();

	void            TakeDamage(int amount);
	void            RecoverHealth(int amount);
	void            UseMana(double amount);
	void            GainMana(double amount);
	void            LoseHeat(double amount);
	void            GenerateHeat(double amount);
	int             Hp() const;
	int             MaxHp() const;
	int             Mana() const;
	int             MaxMana() const;
	int             Heat() const;
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

