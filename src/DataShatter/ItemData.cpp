#include "ItemData.hpp"

ItemData::ItemData(string const& name, string const& info, int power, int maxDurability)
	: Name(name)
	, Info(info)
	, Power(power)
	, MaxDurability(maxDurability)
{}

ItemData::~ItemData(){}

//To be changed in the future to use libtcod's data storage
void ItemDataStore::LoadData()
{
#define ITEM(NAME, INFO, POWER, DURABILITY) mItemData.push_back(ItemData(NAME, INFO, POWER, DURABILITY));
	ITEM("Sword", "It's sharp", 5, 10);
#undef ITEM
}

ItemData const& ItemDataStore::GetData(int id)
{
	return mItemData.at(id);
}

vector<ItemData> ItemDataStore::mItemData;

