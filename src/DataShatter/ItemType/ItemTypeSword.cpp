#include "ItemTypeSword.hpp"
#include "Ability/Ability.hpp"
#include "EquipmentSlots.hpp"
#include "ItemTypes.hpp"
#include <typeinfo>

vector<Ability const*> ItemType_Sword::GetAbilities(iItemType const* offhand) const
{
	vector<Ability const*> abilities;
	abilities.push_back(&Sword01);
	abilities.push_back(&Sword02);
	if( offhand ){
		abilities.push_back(offhand->OffhandAbility());
		auto offhand_type = typeid(*offhand).hash_code();

		OFFHAND_IS(Sword, SwordSword);
		OFFHAND_IS(Shield, SwordShield);
	}
	return abilities;
}
Ability const* ItemType_Sword::OffhandAbility() const { return &Sword03; }

ItemType_Sword const ItemType::Sword;

