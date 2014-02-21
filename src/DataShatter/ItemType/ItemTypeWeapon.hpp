#ifndef ITEMTYPE_WEAPON_HPP
#define ITEMTYPE_WEAPON_HPP

#include "ItemType.hpp"

class ItemType_Weapon : public iItemType{
public:
	ItemType_Weapon(){}
	virtual ~ItemType_Weapon(){}

	EquipSlot GetEquipSlot() const;
	virtual vector<Ability const*> GetAbilities(iItemType const* offhand) const =0;
	virtual Ability const* OffhandAbility() const =0;
};

#endif

