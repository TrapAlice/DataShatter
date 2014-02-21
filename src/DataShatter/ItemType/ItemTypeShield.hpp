#ifndef ITEMTYPE_SHIELD_HPP
#define ITEMTYPE_SHIELD_HPP

#include "ItemTypeWeapon.hpp"

class ItemType_Shield : public ItemType_Weapon{
public:
	ItemType_Shield(){}
	vector<Ability const*> GetAbilities(iItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

namespace ItemType{
	extern ItemType_Shield const Shield;
}

#endif

