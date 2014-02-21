#ifndef ITEMTYPE_HPP
#define ITEMTYPE_HPP

#include "common.hpp"

enum class SkillType;
enum class EquipSlot;
class Ability;


class iItemType{
public:
	iItemType();
	virtual ~iItemType();

//	virtual SkillType GetSkill() = 0;
	virtual EquipSlot GetEquipSlot() const = 0;
	virtual vector<Ability const*> GetAbilities(iItemType const* offhand) const;
	virtual Ability const* OffhandAbility() const;
private:
};

#endif

