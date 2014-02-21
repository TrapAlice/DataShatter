#ifndef ITEMTYPE_SHIELD_HPP
#define ITEMTYPE_SHIELD_HPP

#include "ItemType.hpp"

class ItemType_Shield : public iItemType{
public:
	ItemType_Shield();
	~ItemType_Shield();

	EquipSlot GetEquipSlot() const;
	vector<Ability const*> GetAbilities(iItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

namespace ItemType{
	extern ItemType_Shield const Shield;
}

#endif

