#include "Item.hpp"
#include "ItemData.hpp"

PRIVATE_VARIABLES(Item){
	PrivateVariables(ItemData const& data)
		: data(data)
	{}
	ItemData const& data;
	int             durability;
	int             maxDurability;
};

Item::Item(ItemData const& data)
	: INIT_PRIVATE_VARIABLES(data)
{}

Item::Item(Item&& item) noexcept
	: INIT_PRIVATE_VARIABLES(item.m->data)
{
	m->durability = item.m->durability;
	m->maxDurability = item.m->maxDurability;
}

Item::~Item() noexcept {}

ItemData const& Item::Data() const { return m->data; }

