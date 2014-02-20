#include "Item.hpp"
#include "ItemData.hpp"

PRIVATE_VARIABLES(Item){
	PrivateVariables(ItemData const& data)
		: data(data)
		, durability(data.MaxDurability)
	{}
	ItemData const& data;
	int             durability;
};

Item::Item(ItemData const& data)
	: INIT_PRIVATE_VARIABLES(data)
{}

Item::Item(Item&& item) noexcept
	: INIT_PRIVATE_VARIABLES(item.m->data)
{
	m->durability = item.m->durability;
}

Item::~Item() noexcept {}

ItemData const& Item::Data() const { return m->data; }
string Item::Name() const { return m->data.Name; }
string Item::Info() const { return m->data.Info; }
//ItemType Item::Type() const { return m->data.Type; }
//ItemSkill Item::Skill() const { return m->data.Skill; }
int Item::Power() const { return m->data.Power; }
int Item::Durability() const { return m->durability; }
int Item::MaxDurability() const { return m->data.MaxDurability; }

