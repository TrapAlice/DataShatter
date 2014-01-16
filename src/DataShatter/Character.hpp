#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Item;
class Equipment;
class Ability;

enum class BonusType;
enum class ItemSkill;

class Character{
public:
	Character();
	~Character();

	void            TakeDamage(int amount);
	void            RecoverHealth(int amount);
	void            UseMana(double amount);
	void            GainMana(double amount);
	void            LoseHeat(double amount);
	void            GenerateHeat(double amount);
	void            GiveItem(Item);
	void            Equip(Item const&);
	void            Equip(Item const&, int EquippedLocation);
	int             Hp() const;
	int             MaxHp() const;
	int             Mana() const;
	int             MaxMana() const;
	int             Heat() const;
	vector<Item> const& Items() const;
	Equipment&      GetEquipment() const;
	int             Bonus(BonusType) const;
	std::array<Ability const*, 8> GetAbilities() const;
private:
	HAS_PRIVATE_VARIABLES;
	HAS_PRIVATE_FUNCTIONS;
	//void            ChangeWeaponAbilities(ItemSkill const, int EquippedLocation);
};

#endif

