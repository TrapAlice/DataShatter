#include "ItemType.hpp"
#include "Ability.hpp"
#include "EquipmentSlots.hpp"
#include <typeinfo>

iItemType::iItemType(){}
iItemType::~iItemType(){}

vector<Ability const*> iItemType::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* iItemType::OffhandAbility() const { return 0; }

ItemType_Sword::ItemType_Sword(){}
ItemType_Sword::~ItemType_Sword(){}

EquipSlot ItemType_Sword::GetEquipSlot() { return EquipSlot::Hand; }
vector<Ability const*> ItemType_Sword::GetAbilities(iItemType const* offhand) const
{
	vector<Ability const*> abilities;
	abilities.push_back(&Sword01);
	abilities.push_back(&Sword02);
	if( offhand ){
		abilities.push_back(offhand->OffhandAbility());
		auto offhand_type = typeid(*offhand).hash_code();

#define OFFHAND_IS(TYPE, SKILL) if( offhand_type == typeid(ItemType_##TYPE).hash_code() )\
		                	abilities.push_back(&SKILL);
		OFFHAND_IS(Sword, SwordSword);
		OFFHAND_IS(Shield, SwordShield);
#undef OFFHAND_IS

	}
	return abilities;
}
Ability const* ItemType_Sword::OffhandAbility() const { return &Sword03; }

ItemType_Shield::ItemType_Shield(){}
ItemType_Shield::~ItemType_Shield(){}

EquipSlot ItemType_Shield::GetEquipSlot() { return EquipSlot::Hand; }
vector<Ability const*> ItemType_Shield::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* ItemType_Shield::OffhandAbility() const { return &Shield03; }

