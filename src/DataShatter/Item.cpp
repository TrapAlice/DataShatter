#include "Item.hpp"
#include "ItemData.hpp"

struct Item::PrivateVariables{
	PrivateVariables(ItemData const& data)
		: data(data)
	{}
	ItemData const& data;
	int             durability;
	int             maxDurability;
};

Item::Item(ItemData const& data)
	: INIT_PRIVATE_VARIABLES_WITH(data)
{}

Item::~Item(){}

ItemData const& Item::Data() const { return m->data; }

