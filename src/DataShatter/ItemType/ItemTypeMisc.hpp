#ifndef ITEMTYPE_MISC_HPP
#define ITEMTYPE_MISC_HPP

#include "ItemType.hpp"

class ItemType_Misc : public iItemType{
public:
	ItemType_Misc(){}
};

namespace ItemType{
	extern ItemType_Misc const Misc;
}

#endif

