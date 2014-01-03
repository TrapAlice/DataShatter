#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"
#include "DataShatter/Item.hpp"
#include "DataShatter/ItemData.hpp"
#include "DataShatter/Equipment.hpp"

TEST(CharacterHp,
	Character c;
	TEST_EQ(c.Hp(), c.MaxHp());
	c.TakeDamage(10);
	TEST_NEQ(c.Hp(), c.MaxHp());
	TEST_EQ(c.Hp(), c.MaxHp() - 10);

	c.TakeDamage(100000);
	TEST_EQ(c.Hp(), 0);

	c.RecoverHealth(10);
	TEST_EQ(c.Hp(), 10);

	c.RecoverHealth(100000);
	TEST_EQ(c.Hp(), c.MaxHp());
)

TEST(CharacterMana,
	Character c;
	TEST_EQ(c.Mana(), c.MaxMana());
	c.UseMana(10);
	TEST_NEQ(c.Mana(), c.MaxMana());
	TEST_EQ(c.Mana(), c.MaxMana() - 10);

	c.UseMana(100000);
	TEST_EQ(c.Mana(), 0);

	c.GainMana(10);
	TEST_EQ(c.Mana(), 10);

	c.GainMana(100000);
	TEST_EQ(c.Mana(), c.MaxMana());
)

TEST(CharacterHeat,
	Character c;
	TEST_EQ(c.Heat(), 0);

	c.GenerateHeat(10);
	TEST_EQ(c.Heat(), 10);

	c.GenerateHeat(100000);
	TEST_EQ(c.Heat(), 100);

	c.LoseHeat(10);
	TEST_EQ(c.Heat(), 90);

	c.LoseHeat(100000);
	TEST_EQ(c.Heat(), 0);
)

TEST(CharacterItems,
	Character c;
	ItemDataStore ids;
	auto& inventory = c.Items();
	TEST_CHECK(inventory.empty());

	ItemDataStore::AddItem({"Box", "", ItemType::Misc, 0, 1});
	c.GiveItem({ItemDataStore::GetData(0)});
	TEST_CHECK(!inventory.empty());
	TEST_EQ(inventory.size(), 1);

	auto itemName = inventory[0].Data().Name;
	TEST_EQ(itemName, "Box");
	
	for( int x = 0; x < 5; ++x ) c.GiveItem({ItemDataStore::GetData(0)});
	TEST_EQ(inventory.size(), 6);
	TEST_EQ(inventory[0].Data().Name, "Box");
)

TEST(CharacterEquip,
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem({"Sword", "", ItemType::Weapon | ItemType::Hands, 5, 5});
	c.GiveItem({ItemDataStore::GetData(0)});

	auto& sword = c.Items()[0];
	c.Equip(sword);
	auto& equipment = c.GetEquipment();
	auto weapon = equipment.Equipped(RIGHT_HAND);
	TEST_REQUIRE(weapon);
	TEST_EQ(weapon->Data().Name, "Sword");

	TEST_EQ(c.Bonus(BonusType::Attack), 5);
)

TEST(CharacterMultiEquip,
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem({"Sword", "", ItemType::Weapon | ItemType::Hands, 5, 5});
	ItemDataStore::AddItem({"Shield", "", ItemType::Armor | ItemType::Hands, 2, 10});
	c.GiveItem({ItemDataStore::GetData(0)});
	c.GiveItem({ItemDataStore::GetData(1)});

	c.Equip(c.Items()[0]);
	c.Equip(c.Items()[1], LEFT_HAND);
	auto& equipment = c.GetEquipment();
	auto weapon = equipment.Equipped(RIGHT_HAND);
	auto shield = equipment.Equipped(LEFT_HAND);
	
	TEST_REQUIRE(weapon);
	TEST_REQUIRE(shield);
	TEST_EQ(weapon->Data().Name, "Sword");
	TEST_EQ(shield->Data().Name, "Shield");

	TEST_EQ(c.Bonus(BonusType::Attack), 5);
	TEST_EQ(c.Bonus(BonusType::Defense), 2);
)

