#ifndef ITEMTYPE_WEAPON_HPP
#define ITEMTYPE_WEAPON_HPP

#include "ItemType.hpp"

#define OFFHAND_IS(TYPE, SKILL) if( offhand_type == typeid(ItemType_##TYPE).hash_code() )\
abilities.push_back(&SKILL);

class ItemType_Weapon : public iItemType{
public:
	EquipSlot GetEquipSlot() const { return EquipSlot::Hand; }
	virtual vector<Ability const*> GetAbilities(iItemType const* offhand) const =0;
	virtual Ability const* OffhandAbility() const =0;
};

#endif

