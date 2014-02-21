#ifndef ITEMTYPE_SWORD_HPP
#define ITEMTYPE_SWORD_HPP

#include "ItemType.hpp"

class ItemType_Sword : public iItemType{
public:
	ItemType_Sword();
	~ItemType_Sword();

//	SkillType GetSkill();
	EquipSlot GetEquipSlot() const;
	vector<Ability const*> GetAbilities(iItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

namespace ItemType{
	extern ItemType_Sword const Sword;
}

#endif

