#ifndef ITEMDATA_HPP
#define ITEMDATA_HPP

#include "common.hpp"

enum class ItemType{
	Misc,
	Weapon,
	Armor,
};

enum class ItemSkill{
	NA,
	Sword,
	Shield,
};

enum class ItemEquipSlot{
	NA,
	Hand,
};

struct ItemData{
	ItemData(string const& name, string const& info,
		ItemType, ItemSkill, ItemEquipSlot,
	    int power, int maxDurability);
	~ItemData();
	string          Name;
	string          Info;
	ItemType        Type;
	ItemSkill       Skill;
	ItemEquipSlot   EquipSlot;
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

