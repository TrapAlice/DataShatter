#ifndef ITEM_HPP
#define ITEM_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

struct ItemData;

class Item{
public:
	Item(ItemData const& data);
	Item(Item&&) noexcept;
	~Item() noexcept;
	ItemData const& Data() const;
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

