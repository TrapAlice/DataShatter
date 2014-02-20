#include "ItemData.hpp"
#include "ItemType.hpp"

ItemData::ItemData(string const& name, string const& info,
	iItemType const* type,// ItemSkill skill, ItemEquipSlot equipSlot,
	int power, int maxDurability)
	: Name(name)
	, Info(info)
	, Type(type)
	//, Skill(skill)
	//, EquipSlot(equipSlot)
	, Power(power)
	, MaxDurability(maxDurability)
{}

ItemData::~ItemData(){}

//To be changed in the future to use libtcod's data storage
void ItemDataStore::LoadData()
{
#define ITEM(NAME, INFO, TYPE,  POWER, DURABILITY)\
	AddItem(ItemData(NAME, INFO, TYPE, POWER, DURABILITY));
	ITEM("Sword", "It's sharp", new ItemType_Sword(), 5, 10);
	ITEM("Shield", "It can block things", new ItemType_Shield(), 2, 5);
	//ITEM("Sword", "It's sharp", ItemType::Weapon, ItemSkill::Sword, ItemEquipSlot::Hand, 5, 10);
	//ITEM("Shield", "It can block things", ItemType::Weapon, ItemSkill::Shield, ItemEquipSlot::Hand, 2, 5);
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

//std::ostream& operator<< (std::ostream& os, const ItemType type)
//{
//	switch(type){
//		case ItemType::Misc: os << "Miscellaneous "; break;
//		case ItemType::Weapon: os << "Weapon "; break;
//		case ItemType::Armor: os << "Armor "; break;
//	}
//	return os;
//}
//
//std::ostream& operator<< (std::ostream& os, const ItemSkill skill)
//{
//	switch(skill){
//		case ItemSkill::Sword: os << "Sword "; break;
//		case ItemSkill::Shield: os << "Shield "; break;
//		case ItemSkill::NA: os << ""; break;
//	}
//	return os;
//}

