#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "common.hpp"

class Item;
class Equipment;

enum class BonusType;

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
	void            GiveItem(Item);
	void            Equip(Item const&);
	void            Equip(Item const&, int EquippedLocation);
	int             Hp() const;
	int             MaxHp() const;
	int             Mana() const;
	int             MaxMana() const;
	int             Heat() const;
	vector<Item> const& Items() const;
	Equipment&      GetEquipment() const;
	int             Bonus(BonusType) const;
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

