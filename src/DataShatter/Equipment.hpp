#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "common.hpp"

class Item;
class Ability;

enum EquippedLocation{
	RIGHT_HAND,
	LEFT_HAND,
	EQUIPMENT_SLOTS,
};

enum class BonusType{
	Attack,
	Defense,
};

class Equipment{
public:
	Equipment();
	~Equipment();
	void            Equip(Item const&);
	void            Equip(Item const&, int location);
	Item const*     Equipped(EquippedLocation);
	int             Bonus(BonusType);
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

