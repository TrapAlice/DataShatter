#include "Equipment.hpp"
#include "Item.hpp"
#include "ItemData.hpp"

#include <array>

struct Equipment::PrivateVariables{
	std::array<Item const*, EQUIPMENT_SLOTS> equipment;
};

Equipment::Equipment()
	: INIT_PRIVATE_VARIABLES
{}

Equipment::~Equipment()
{}

void Equipment::Equip(Item const& item)
{
	m->equipment[0] = &item;
}

Item const* Equipment::Equipped(EquippedLocation slot)
{
	return m->equipment[slot];
}

int Equipment::AttackBonus()
{
	int bonus = 0;
	for( int x = 0; x < EQUIPMENT_SLOTS; ++x ){
		bonus += m->equipment[x]->Data().Power;
	}
	return bonus;
}

