#ifndef ITEMDATA_HPP
#define ITEMDATA_HPP

#include "common.hpp"

class iItemType;

struct ItemData{
	ItemData(string const& name, string const& info,
		iItemType const*,
	    int power, int maxDurability);
	~ItemData();
	string          Name;
	string          Info;
	iItemType const* Type;
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

