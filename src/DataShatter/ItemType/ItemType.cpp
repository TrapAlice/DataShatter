#include "ItemType.hpp"
#include "Ability.hpp"
#include "EquipmentSlots.hpp"
#include <typeinfo>

iItemType::iItemType(){}
iItemType::~iItemType(){}

vector<Ability const*> iItemType::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* iItemType::OffhandAbility() const { return 0; }


