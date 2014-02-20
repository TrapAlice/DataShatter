#include "ItemType.hpp"
#include "Ability.hpp"
#include "EquipmentSlots.hpp"
#include <typeinfo>

iItemType::iItemType(){}
iItemType::~iItemType(){}

vector<Ability const*> iItemType::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* iItemType::OffhandAbility() const { return 0; }


ItemType_Shield::ItemType_Shield(){}
ItemType_Shield::~ItemType_Shield(){}

EquipSlot ItemType_Shield::GetEquipSlot() { return EquipSlot::Hand; }
vector<Ability const*> ItemType_Shield::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* ItemType_Shield::OffhandAbility() const { return &Shield03; }

const ItemType_Shield ItemType::Shield;

