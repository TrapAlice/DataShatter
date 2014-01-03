#include "UnitTest.hpp"
#include "DataShatter/Character.hpp"

TEST(CharacterHp,
	Character character;
	int hp = character.Hp();
	character.TakeDamage(10);
	int currentHp = character.Hp();
	TEST_NEQ(currentHp, hp);
	TEST_EQ(currentHp, hp - 10);

	character.TakeDamage(100000);
	currentHp = character.Hp();
	TEST_EQ(currentHp, 0);

	character.RecoverHealth(10);
	currentHp = character.Hp();
	TEST_EQ(currentHp, 10);

	character.RecoverHealth(100000);
	currentHp = character.Hp();
	int maxHp = character.MaxHp();
	TEST_EQ(currentHp, maxHp);
)

