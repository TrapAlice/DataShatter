#include "ItemData.hpp"

ItemData::ItemData(string const& name, string const& info, int power, int maxDurability)
	: Name(name)
	, Info(info)
	, Power(power)
	, MaxDurability(maxDurability)
{}

ItemData::~ItemData(){}
