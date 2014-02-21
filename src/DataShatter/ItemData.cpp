#include "ItemData.hpp"
#include "ItemType/ItemTypes.hpp"

ItemData::ItemData(string const& name, string const& info,
	iItemType const* type,
	int power, int maxDurability)
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
#define ITEM(NAME, INFO, TYPE,  POWER, DURABILITY)\
	AddItem(ItemData(NAME, INFO, TYPE, POWER, DURABILITY));
	ITEM("Sword", "It's sharp", &ItemType::Sword, 5, 10);
	ITEM("Shield", "It can block things", &ItemType::Shield, 2, 5);
#undef ITEM
}

void ItemDataStore::AddItem(ItemData const& data)
{
	mItemData.push_back(data);
}

ItemData const& ItemDataStore::GetData(int id)
{
	if( mItemData.empty() ) LoadData();
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

