#include "Equipment.hpp"
#include "Item.hpp"
#include "ItemData.hpp"
#include "Ability.hpp"

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
	if( item.Data().EquipSlot == ItemEquipSlot::Hand )
		m->equipment[RIGHT_HAND] = &item;
}

void Equipment::Equip(Item const& item, int location)
{
	if( item.Data().EquipSlot == ItemEquipSlot::Hand &&
		!(location != RIGHT_HAND || location != LEFT_HAND))
		return;
	m->equipment[location] = &item;
}

Item const* Equipment::Equipped(EquippedLocation slot)
{
	return m->equipment[slot];
}

int Equipment::Bonus(BonusType type)
{
	int bonus = 0;
	for ( int x = 0; x < EQUIPMENT_SLOTS; ++x ){
		auto item = m->equipment[x];
		if( !item ) continue;
		switch( type ){
			case BonusType::Attack:
				if( !(item->Data().Type == ItemType::Weapon) )
					continue;
				break;
			case BonusType::Defense:
				if( !(item->Data().Type == ItemType::Armor) )
					continue;
				break;
		}
		bonus += m->equipment[x]->Data().Power;
	}
	return bonus;
}

