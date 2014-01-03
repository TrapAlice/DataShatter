#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "common.hpp"

class Item;

enum EquippedLocation{
	RIGHT_HAND,
	LEFT_HAND,
	EQUIPMENT_SLOTS,
};

class Equipment{
public:
	Equipment();
	~Equipment();
	void            Equip(Item const&);
	void            Equip(Item const&, int location);
	Item const*     Equipped(EquippedLocation);
	int             AttackBonus();
	int             DefenseBonus();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

