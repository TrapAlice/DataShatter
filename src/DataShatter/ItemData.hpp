#ifndef ITEMDATA_HPP
#define ITEMDATA_HPP

#include "common.hpp"

struct ItemData{
	ItemData(string const& name, string const& info, int power, int maxDurability);
	~ItemData();
	string          Name;
	string          Info;
	int             Power;
	int             MaxDurability;
};

class ItemDataStore{
public:
	static void     LoadData();
	static ItemData const& GetData(int id);
private:
	static vector<ItemData> mItemData;
};

#endif

