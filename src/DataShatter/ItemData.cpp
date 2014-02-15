#include "ItemData.hpp"

ItemData::ItemData(string const& name, string const& info,
	ItemType type, ItemSkill skill, ItemEquipSlot equipSlot,
	int power, int maxDurability)
	: Name(name)
	, Info(info)
	, Type(type)
	, Skill(skill)
	, EquipSlot(equipSlot)
	, Power(power)
	, MaxDurability(maxDurability)
{}

ItemData::~ItemData(){}

//To be changed in the future to use libtcod's data storage
void ItemDataStore::LoadData()
{
#define ITEM(NAME, INFO, TYPE, SKILL, LOCATION,  POWER, DURABILITY)\
	AddItem(ItemData(NAME, INFO, TYPE, SKILL, LOCATION, POWER, DURABILITY));
	ITEM("Sword", "It's sharp", ItemType::Weapon, ItemSkill::Sword, ItemEquipSlot::Hand, 5, 10);
	ITEM("Shield", "It can block things", ItemType::Weapon, ItemSkill::Shield, ItemEquipSlot::Hand, 2, 5);
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

