#include "ItemTypeShield.hpp"
#include "Ability/Ability.hpp"
#include "EquipmentSlots.hpp"
#include "ItemTypes.hpp"
#include <typeinfo>

vector<Ability const*> ItemType_Shield::GetAbilities(iItemType const* offhand) const
{
	vector<Ability const*> abilities;
	abilities.push_back(&Shield01);
	abilities.push_back(&Shield02);
	if( offhand ){
		abilities.push_back(offhand->OffhandAbility());
		auto offhand_type = typeid(*offhand).hash_code();

		OFFHAND_IS(Sword, ShieldSword);
		OFFHAND_IS(Shield, ShieldShield);
	}
	return abilities;
}
Ability const* ItemType_Shield::OffhandAbility() const { return &Shield03; }

ItemType_Shield const ItemType::Shield;

