#ifndef ITEM_HPP
#define ITEM_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

struct ItemData;
//enum class ItemType;
//enum class ItemSkill;
class ItemType;

class Item{
public:
	Item(ItemData const& data);
	Item(Item&&) noexcept;
	~Item() noexcept;
	ItemData const& Data() const;
	string          Name() const;
	string          Info() const;
	//ItemType        Type() const;
	//ItemSkill       Skill() const;
	int             Power() const;
	int             Durability() const;
	int             MaxDurability() const;

private:
	HAS_PRIVATE_VARIABLES;
};

#endif

