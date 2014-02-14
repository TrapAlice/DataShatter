#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"
#include "DataShatter/Enemy.hpp"
#include "DataShatter/Item.hpp"
#include "DataShatter/ItemData.hpp"
#include "DataShatter/Equipment.hpp"

namespace{
	ItemData sword{"Sword", "", ItemType::Weapon, ItemSkill::Sword, ItemEquipSlot::Hand, 5, 5};
	ItemData shield{"Shield", "", ItemType::Armor, ItemSkill::Shield,ItemEquipSlot::Hand, 2, 5};
}


TEST(Battle, CharacterUseSkill){
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem(sword);
	ItemDataStore::AddItem(shield);
	c.GiveItem({ItemDataStore::GetData(0)});
	c.GiveItem({ItemDataStore::GetData(1)});
	c.Equip(c.Items()[0]);
	c.Equip(c.Items()[1], LEFT_HAND);
	Enemy e;
	c.UseSkill(1, e);

	TEST_CHECK(c.Mana() < c.MaxMana());
	TEST_CHECK(c.Heat() > 0);
	TEST_CHECK(e.Hp() < e.MaxHp());
}

