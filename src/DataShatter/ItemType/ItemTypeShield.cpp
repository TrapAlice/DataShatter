#include "ItemTypeShield.hpp"
#include "Ability.hpp"
#include "EquipmentSlots.hpp"
#include <typeinfo>

ItemType_Shield::ItemType_Shield(){}
ItemType_Shield::~ItemType_Shield(){}

vector<Ability const*> ItemType_Shield::GetAbilities(iItemType const* offhand) const { return {}; }
Ability const* ItemType_Shield::OffhandAbility() const { return &Shield03; }

ItemType_Shield const ItemType::Shield;

