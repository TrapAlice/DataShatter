#ifndef ITEMTYPE_HPP
#define ITEMTYPE_HPP

#include "common.hpp"
#include "EquipmentSlots.hpp"

enum class SkillType;
enum class EquipSlot;
class Ability;


class iItemType{
public:
//	virtual SkillType GetSkill() = 0;
	virtual EquipSlot GetEquipSlot() const { return EquipSlot::NA; }
	virtual vector<Ability const*> GetAbilities(iItemType const* offhand) const { return {}; }
	virtual Ability const* OffhandAbility() const { return nullptr; }
private:
};

#endif

