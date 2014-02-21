#ifndef ITEMTYPE_SWORD_HPP
#define ITEMTYPE_SWORD_HPP

#include "ItemTypeWeapon.hpp"

class ItemType_Sword : public ItemType_Weapon{
public:
	ItemType_Sword();
	~ItemType_Sword();

//	SkillType GetSkill();
	vector<Ability const*> GetAbilities(iItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

namespace ItemType{
	extern ItemType_Sword const Sword;
}

#endif

