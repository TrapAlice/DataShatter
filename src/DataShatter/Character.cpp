#include "Character.hpp"
#include "Item.hpp"
#include "ItemData.hpp"
#include "ItemType/ItemTypes.hpp"
#include "Equipment.hpp"
#include "Ability/Ability.hpp"
#include "Enemy.hpp"
#include "GlobalTime.hpp"
#include "Condition.hpp"
#include "SpecWarrior.hpp"
#include "EquipmentSlots.hpp"

PRIVATE_VARIABLES(Character){
	double          heat = 0;
	vector<Item>    items;
	Equipment       equipment;
	std::array<Ability const*, 8> abilities;
	unsigned        cooldown = 0;
	unique_ptr<Spec> spec;
};

PRIVATE_FUNCTIONS(Character){
	PRIVATE_FUNCTION_DECLARE(void, ChangeWeaponAbilities){
		auto& equipment = This->m->equipment;
		auto right_hand = equipment.Equipped(RIGHT_HAND);
		if( !right_hand ) return;
		auto right_skill = right_hand->Data().Type;
		auto left_hand =  equipment.Equipped(LEFT_HAND);
		iItemType const* left_skill = 0;
		if( left_hand ){
			left_skill = left_hand->Data().Type;
		}

		auto weapon_abilities = right_skill->GetAbilities(left_skill);
		for( unsigned x = 0; x < weapon_abilities.size(); ++x ){
			This->ReplaceAbility(x+1, *weapon_abilities[x]);
		}
	};
};

Character::Character()
	: INIT_PRIVATE_VARIABLES()
{
	m->spec.reset(new Spec_Warrior);
}
Character::~Character(){}

void Character::LoseHeat(double amount)
{
	m->heat -= (m->heat - amount > 0)? amount : m->heat;
}

void Character::GenerateHeat(double amount)
{
	m->heat = (m->heat + amount > 100)? 100 : m->heat + amount;
}

void Character::UseSkill(int skill, Enemy& target)
{
    Ability const& ability = *m->abilities[skill-1];
	if( ability.ManaCost() > Mana() ) return;
	if( isCooldown() ) return;
	ability.Activate(*this, target);
    UseMana(ability.ManaCost());
    GenerateHeat(ability.Heat());
    m->cooldown = GlobalTime::Current() + ability.Cooldown() + 150;
}

void Character::Update(Combatant& target)
{
	Conditions().remove_if([](Condition& c){ return c.isExpired(); });
}

void Character::BattleEnd()
{
	GainMana(MaxMana());
}

bool Character::GainExp(unsigned amount)
{
	return m->spec->GainExp(amount);
}

void Character::GiveItem(Item item)
{
	m->items.emplace_back(std::move(item));
}

void Character::Equip(Item const& item)
{
	m->equipment.Equip(item);
	if( item.Type()->GetEquipSlot() == EquipSlot::Hand ){
		PRIVATE(ChangeWeaponAbilities);
	}
}

void Character::Equip(Item const& item, int location)
{
	m->equipment.Equip(item, location);
	if( item.Type()->GetEquipSlot() == EquipSlot::Hand ){
		PRIVATE(ChangeWeaponAbilities);
	}
}

void Character::ReplaceAbility(unsigned pos, Ability const& ability)
{
	m->abilities[pos-1] = &ability;
}

int Character::Heat() const { return m->heat; }
bool Character::isCooldown() const { return m->cooldown > GlobalTime::Current() - 150; }
const vector<Item>& Character::Items() const { return m->items; }
Equipment& Character::GetEquipment() const { return m->equipment; }
int Character::Bonus(BonusType type) const { return m->equipment.Bonus(type); }
unsigned Character::Exp() const { return m->spec->Exp(); }
std::array<Ability const*, 8> Character::GetAbilities() const { return m->abilities; }
Spec& Character::GetSpec() const { return *m->spec; }

