#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"
#include "DataShatter/Item.hpp"
#include "DataShatter/ItemData.hpp"
#include "DataShatter/Equipment.hpp"
#include "DataShatter/Ability.hpp"

namespace{
	ItemData sword{"Sword", "", ItemType::Weapon, ItemSkill::Sword, ItemEquipSlot::Hand, 5, 5};
	ItemData shield{"Shield", "", ItemType::Armor, ItemSkill::Shield,ItemEquipSlot::Hand, 2, 5};
}

TEST(Character, Hp){
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
}

TEST(Character, Mana){
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
}

TEST(Character, Heat){
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
}

TEST(Character, Items){
	Character c;
	ItemDataStore ids;
	auto& inventory = c.Items();
	TEST_CHECK(inventory.empty());

	ItemDataStore::AddItem({"Box", "", ItemType::Misc, ItemSkill::NA, ItemEquipSlot::NA, 0, 1});
	c.GiveItem({ItemDataStore::GetData(0)});
	TEST_CHECK(!inventory.empty());
	TEST_EQ(inventory.size(), 1);

	auto itemName = inventory[0].Data().Name;
	TEST_EQ(itemName, "Box");
	
	for( int x = 0; x < 5; ++x ) c.GiveItem({ItemDataStore::GetData(0)});
	TEST_EQ(inventory.size(), 6);
	TEST_EQ(inventory[0].Data().Name, "Box");
}

TEST(Character, Equip){
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem(sword);
	c.GiveItem({ItemDataStore::GetData(0)});

	auto& sword = c.Items()[0];
	c.Equip(sword);
	auto& equipment = c.GetEquipment();
	auto weapon = equipment.Equipped(RIGHT_HAND);
	TEST_REQUIRE(weapon);
	TEST_EQ(weapon->Data().Name, "Sword");

	TEST_EQ(c.Bonus(BonusType::Attack), 5);
}

TEST(Character, MultiEquip){
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem(sword);
	ItemDataStore::AddItem(shield);
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
}

TEST(Character, EquippedSkills){
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem(sword);
	ItemDataStore::AddItem(shield);
	c.GiveItem({ItemDataStore::GetData(0)});
	c.GiveItem({ItemDataStore::GetData(1)});
	c.Equip(c.Items()[0]);
	c.Equip(c.Items()[1], LEFT_HAND);
	
	auto abilities = c.GetAbilities();
	TEST_REQUIRE(abilities[0]);
	TEST_REQUIRE(abilities[1]);
	TEST_REQUIRE(abilities[2]);
	TEST_REQUIRE(abilities[3]);
	TEST_EQ(abilities[0]->Name(), "Sword-Skill01");
	TEST_EQ(abilities[1]->Name(), "Sword-Skill02");
	TEST_EQ(abilities[2]->Name(), "Shield-Skill03");
	TEST_EQ(abilities[3]->Name(), "SwordShield-Skill");
}

TEST(Character, SwappingEquippedSkills){
	Character c;
	ItemDataStore ids;
	ItemDataStore::AddItem(sword);
	ItemDataStore::AddItem(shield);
	c.GiveItem({ItemDataStore::GetData(0)});
	c.GiveItem({ItemDataStore::GetData(0)});
	c.GiveItem({ItemDataStore::GetData(1)});
	c.Equip(c.Items()[0]);
	c.Equip(c.Items()[1], LEFT_HAND);

	auto abilities = c.GetAbilities();
	TEST_EQ(abilities[2]->Name(), "Sword-Skill03");
	TEST_EQ(abilities[3]->Name(), "SwordSword-Skill");

	c.Equip(c.Items()[2], LEFT_HAND);
	abilities = c.GetAbilities();
	TEST_EQ(abilities[2]->Name(), "Shield-Skill03");
	TEST_EQ(abilities[3]->Name(), "SwordShield-Skill");

	c.Equip(c.Items()[2], RIGHT_HAND);
	c.Equip(c.Items()[0], LEFT_HAND);
	abilities = c.GetAbilities();
	TEST_EQ(abilities[0]->Name(), "Shield-Skill01");
	TEST_EQ(abilities[1]->Name(), "Shield-Skill02");
	TEST_EQ(abilities[2]->Name(), "Sword-Skill03");
	TEST_EQ(abilities[3]->Name(), "ShieldSword-Skill");
}

