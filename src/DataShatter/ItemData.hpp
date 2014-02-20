#ifndef ITEMDATA_HPP
#define ITEMDATA_HPP

#include "common.hpp"

//enum class ItemType{
//	Misc,
//	Weapon,
//	Armor,
//};
//std::ostream& operator<< (std::ostream&, const ItemType);
//
//enum class ItemSkill{
//	Sword,
//	Shield,
//	NA,
//};
//std::ostream& operator<< (std::ostream&, const ItemSkill);
//
//enum class ItemEquipSlot{
//	NA,
//	Hand,
//};

class ItemType;

struct ItemData{
	ItemData(string const& name, string const& info,
		ItemType const*,// ItemSkill, ItemEquipSlot,
	    int power, int maxDurability);
	~ItemData();
	string          Name;
	string          Info;
	ItemType const* Type;
	//ItemSkill       Skill;
	//ItemEquipSlot   EquipSlot;
	int             Power;
	int             MaxDurability;
};

class ItemDataStore{
public:
	~ItemDataStore();
	static void     LoadData();
	static void     AddItem(ItemData const&);
	static ItemData const& GetData(int id);
	static void     ClearData();
private:
	static vector<ItemData> mItemData;
};

#endif

