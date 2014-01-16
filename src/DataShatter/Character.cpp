#include "Character.hpp"
#include "Item.hpp"
#include "ItemData.hpp"
#include "Equipment.hpp"
#include "Ability.hpp"

PRIVATE_VARIABLES(Character){
	int             hp = 50;
	int             maxHp = 50;
	double          mana = 25;
	double          maxMana = 25;
	double          heat = 0;
	vector<Item>    items;
	Equipment       equipment;
	std::array<Ability const*, 8> abilities;
};

PRIVATE_FUNCTIONS(Character){
	PRIVATE_FUNCTION_DECLARE(void, ChangeWeaponAbilities, ItemSkill const skill, int location){
		int offset = 3 + static_cast<int>(ItemSkill::NA);
		if( location == RIGHT_HAND ){
			This->m->abilities[0] = &AbilityStore::GetAbility(static_cast<int>(skill)*offset);
			This->m->abilities[1] = &AbilityStore::GetAbility(static_cast<int>(skill)*offset + 1);
		} else if( location == LEFT_HAND ) {
			This->m->abilities[2] = &AbilityStore::GetAbility(static_cast<int>(skill)*offset + 2);
		} else return;

		//Get the skills type of the item held in the left and right hand
		if( !This->m->equipment.Equipped(RIGHT_HAND) ) return;
		if( !This->m->equipment.Equipped(LEFT_HAND) )  return;
		auto right_skill = This->m->equipment.Equipped(RIGHT_HAND)->Data().Skill;
		auto left_skill  = This->m->equipment.Equipped(LEFT_HAND)->Data().Skill;
		auto right_id    = static_cast<int>(right_skill);
		auto left_id     = static_cast<int>(left_skill);

		This->m->abilities[3] =
		    &AbilityStore::GetAbility((right_id * offset) + 3 + left_id);
	};
};

Character::Character()
	: INIT_PRIVATE_VARIABLES()
{}
Character::~Character(){}

void Character::TakeDamage(int amount)
{
	m->hp -= (m->hp - amount > 0)? amount : m->hp;
}

void Character::RecoverHealth(int amount)
{
	m->hp = (m->hp + amount > m->maxHp)? m->maxHp : m->hp + amount;
}

void Character::UseMana(double amount)
{
	m->mana -= (m->mana - amount > 0)? amount : m->mana;
}

void Character::GainMana(double amount)
{
	m->mana = (m->mana + amount > m->maxMana)? m->maxMana : m->mana + amount;
}

void Character::LoseHeat(double amount)
{
	m->heat -= (m->heat - amount > 0)? amount : m->heat;
}

void Character::GenerateHeat(double amount)
{
	m->heat = (m->heat + amount > 100)? 100 : m->heat + amount;
}

void Character::GiveItem(Item item)
{
	m->items.emplace_back(std::move(item));
}

void Character::Equip(Item const& item)
{
	m->equipment.Equip(item);
	if( item.Data().EquipSlot == ItemEquipSlot::Hand ){
		PRIVATE(ChangeWeaponAbilities, item.Data().Skill, RIGHT_HAND);
	}
}

void Character::Equip(Item const& item, int location)
{
	m->equipment.Equip(item, location);
	if( item.Data().EquipSlot == ItemEquipSlot::Hand ){
		PRIVATE(ChangeWeaponAbilities, item.Data().Skill, location);
	}
}

int Character::Hp() const { return m->hp; }
int Character::MaxHp() const { return m->maxHp; }
int Character::Mana() const { return m->mana; }
int Character::MaxMana() const { return m->maxMana; }
int Character::Heat() const { return m->heat; }
const vector<Item>& Character::Items() const { return m->items; }
Equipment& Character::GetEquipment() const { return m->equipment; }
int Character::Bonus(BonusType type) const { return m->equipment.Bonus(type); }
std::array<Ability const*, 8> Character::GetAbilities() const { return m->abilities; }

