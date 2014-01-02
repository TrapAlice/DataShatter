#ifndef ITEM_HPP
#define ITEM_HPP

#include "common.hpp"

struct ItemData;

class Item{
public:
	Item(ItemData const& data);
	~Item();
	ItemData const& Data() const;
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

