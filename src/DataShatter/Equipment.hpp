#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "common.hpp"

class Item;

enum EquippedLocation{
	RIGHT_HAND,
	EQUIPMENT_SLOTS,
};

class Equipment{
public:
	Equipment();
	~Equipment();
	void            Equip(Item const&);
	Item const*     Equipped(EquippedLocation);
	int             AttackBonus();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

