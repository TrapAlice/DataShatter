#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"
#include "DataShatter/Enemy.hpp"
#include "DataShatter/Item.hpp"
#include "DataShatter/ItemData.hpp"
#include "DataShatter/Equipment.hpp"
#include "DataShatter/GlobalTime.hpp"

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

TEST(Battle, EnemyAttackCharacter){
	GlobalTime::SetDebugging();
	GlobalTime::Reset();
    Character c;
    Enemy e;

    e.Update(c);
    GlobalTime::SetTime(1000);
    e.Update(c);
    GlobalTime::SetTime(3000);
    e.Update(c);
    GlobalTime::SetTime(5000);
    e.Update(c);

    TEST_CHECK(c.Hp() < c.MaxHp());
    TEST_CHECK(e.Mana() < e.MaxMana());
}

TEST(Battle, CharacterBlocksEnemy){
    Character c;
    Enemy e;
    ItemDataStore ids;
    ItemDataStore::AddItem(sword);
    ItemDataStore::AddItem(shield);
    c.GiveItem({ItemDataStore::GetData(0)});
    c.GiveItem({ItemDataStore::GetData(1)});
    c.Equip(c.Items()[0]);
    c.Equip(c.Items()[1], LEFT_HAND);

    c.UseSkill(3, e);
    c.SetState(CombatantState::Guarding);
    e.Attack(c);

    TEST_EQ(c.Hp(), c.MaxHp());
    TEST_EQ(e.Hp(), e.MaxHp());
}
