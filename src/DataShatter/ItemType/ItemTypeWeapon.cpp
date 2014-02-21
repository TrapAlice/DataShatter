#include "ItemTypeWeapon.hpp"
#include "EquipmentSlots.hpp"

EquipSlot ItemType_Weapon::GetEquipSlot() const
{
	return EquipSlot::Hand;
}
