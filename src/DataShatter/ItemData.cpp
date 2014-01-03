#include "ItemData.hpp"

ItemData::ItemData(string const& name, string const& info, ItemType type, int power, int maxDurability)
	: Name(name)
	, Info(info)
	, Type(type)
	, Power(power)
	, MaxDurability(maxDurability)
{}

ItemData::~ItemData(){}

//To be changed in the future to use libtcod's data storage
void ItemDataStore::LoadData()
{
#define ITEM(NAME, INFO, TYPE, POWER, DURABILITY) AddItem(ItemData(NAME, INFO, TYPE, POWER, DURABILITY));
	ITEM("Sword", "It's sharp", ItemType::Weapon, 5, 10);
#undef ITEM
}

void ItemDataStore::AddItem(ItemData const& data)
{
	mItemData.push_back(data);
}

ItemData const& ItemDataStore::GetData(int id)
{
	return mItemData.at(id);
}

void ItemDataStore::ClearData()
{
	mItemData.clear();
}

vector<ItemData> ItemDataStore::mItemData;

ItemDataStore::~ItemDataStore()
{
	ClearData();
}

