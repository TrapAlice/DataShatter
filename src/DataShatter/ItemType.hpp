#ifndef ITEMTYPE_HPP
#define ITEMTYPE_HPP

#include "common.hpp"

enum class SkillType;
enum class EquipSlot;
class Ability;

class ItemType{
public:
	ItemType();
	virtual ~ItemType();

//	virtual SkillType GetSkill() = 0;
	virtual EquipSlot GetEquipSlot() = 0;
	virtual vector<Ability const*> GetAbilities(ItemType const* offhand) const;
	virtual Ability const* OffhandAbility() const;
private:
};

class ItemType_Sword : public ItemType{
public:
	ItemType_Sword();
	~ItemType_Sword();

//	SkillType GetSkill();
	EquipSlot GetEquipSlot();
	vector<Ability const*> GetAbilities(ItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

class ItemType_Shield : public ItemType{
public:
	ItemType_Shield();
	~ItemType_Shield();

//	SkillType GetSkill();
	EquipSlot GetEquipSlot();
	vector<Ability const*> GetAbilities(ItemType const* offhand) const;
	Ability const* OffhandAbility() const;
};

#endif

