#include "Character.hpp"
#include "Item.hpp"
#include "Equipment.hpp"

struct Character::PrivateVariables{
	int             hp = 50;
	int             maxHp = 50;
	double          mana = 25;
	double          maxMana = 25;
	double          heat = 0;
	vector<Item>    items;
	Equipment       equipment;
};

Character::Character()
	: INIT_PRIVATE_VARIABLES
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
}

void Character::Equip(Item const& item, int location)
{
	m->equipment.Equip(item, location);
}

std::array<Ability const*, 8> Character::GetAbilities() const
{
	std::array<Ability const*, 8> abilities;
	auto weaponAbilities = m->equipment.GetWeaponAbilities();
	abilities[0] = weaponAbilities[0];	
	abilities[1] = weaponAbilities[1];	
	abilities[2] = weaponAbilities[2];	
	abilities[3] = weaponAbilities[3];	
	return abilities;
}

int Character::Hp() const { return m->hp; }
int Character::MaxHp() const { return m->maxHp; }
int Character::Mana() const { return m->mana; }
int Character::MaxMana() const { return m->maxMana; }
int Character::Heat() const { return m->heat; }
const vector<Item>& Character::Items() const { return m->items; }
Equipment& Character::GetEquipment() const { return m->equipment; }
int Character::Bonus(BonusType type) const { return m->equipment.Bonus(type); }

