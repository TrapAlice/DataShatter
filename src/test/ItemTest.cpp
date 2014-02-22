#include "UnitTest.hpp"
#include "Item.hpp"
#include "ItemData.hpp"
#include "ItemType/ItemTypes.hpp"
#include "EquipmentSlots.hpp"

TEST(Items, DefaultValues){
	ItemDataStore::AddItem({"Box", "", &ItemType::Misc, 0, 1});
	auto item = ItemDataStore::GetData(0);

	TEST_CHECK(item.Type->GetEquipSlot() == EquipSlot::NA);
	TEST_CHECK(item.Type->GetAbilities(nullptr).size() == 0);
	TEST_CHECK(item.Type->OffhandAbility() == nullptr);

}
