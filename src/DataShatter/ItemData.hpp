#ifndef ITEMDATA_HPP
#define ITEMDATA_HPP

#include "common.hpp"

enum ItemType{
	Misc            = 0,
	Weapon          = 1 << 1,
	Armor           = 1 << 2,
};

struct ItemData{
	ItemData(string const& name, string const& info, int type, int power, int maxDurability);
	~ItemData();
	string          Name;
	string          Info;
	int             Type;
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

