#include "UnitTest.hpp"
#include "Spec.hpp"

class Spec_Test : public Spec{
public:
	string          Name() const { return "Test"; }
	vector<Ability const*> GetAbilities() const { return {}; }
};

TEST(Spec, GainExpAndLevels){
	Spec_Test t;
	TEST_EQ(t.Exp(), 0);
	t.GainExp(10);
	TEST_EQ(t.Exp(), 10);
	TEST_EQ(t.Level(), 1);
	t.GainExp(1000000);
	TEST_CHECK(t.Level() >= 2);
}
