#include "UnitTest.hpp"
#include "DataShatter/Condition/Condition.hpp"
#include "DataShatter/Condition/ConditionData.hpp"
#include "DataShatter/GlobalTime.hpp"
#include "DataShatter/Enemy.hpp"

TEST(Condition, ConditionExpiring){
	GlobalTime::SetDebugging();
	GlobalTime::Reset();

	Condition c{{ConditionType::On_tick,5,[](Combatant&, Combatant&, int&){}}};
	TEST_CHECK(!c.isExpired());
	GlobalTime::SetTime(4);
	TEST_CHECK(!c.isExpired());
	GlobalTime::SetTime(5);
	TEST_CHECK(c.isExpired());
	GlobalTime::SetTime(6);
	TEST_CHECK(c.isExpired());
}

TEST(Condition, ConditionFunction){
	Condition c{{ConditionType::On_defense, 5,
		[](Combatant&, Combatant&, int& damage){ damage /= 2; }}};
	Enemy blank;

	int damage = 20;
	c.Activate(blank, blank, damage);
	TEST_EQ(damage, 10);
}
