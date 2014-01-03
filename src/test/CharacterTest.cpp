#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"

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

