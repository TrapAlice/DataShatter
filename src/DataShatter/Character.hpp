#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"
#include "Combatant.hpp"

class Item;
class Equipment;
class Ability;
class Enemy;

enum class BonusType;
enum class ItemSkill;

class Character : public Combatant{
public:
	Character();
	~Character();

	void            LoseHeat(double amount);
	void            GenerateHeat(double amount);
	void            UseSkill(int skill, Enemy& target);
	void            GiveItem(Item);
	void            Equip(Item const&);
	void            Equip(Item const&, int EquippedLocation);
	void            Update(Combatant&);
	void            BattleEnd();
	int             Heat() const;
	bool            isCooldown() const;
	vector<Item> const& Items() const;
	Equipment&      GetEquipment() const;
	int             Bonus(BonusType) const;
	std::array<Ability const*, 8> GetAbilities() const;
private:
	HAS_PRIVATE_VARIABLES;
	HAS_PRIVATE_FUNCTIONS;
};

#endif

