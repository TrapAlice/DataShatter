#include "SpecWarrior.hpp"
#include "Ability.hpp"

Spec_Warrior::Spec_Warrior(){}
Spec_Warrior::~Spec_Warrior(){}

string Spec_Warrior::Name() const { return "Warrior"; }
vector<Ability const*> Spec_Warrior::GetAbilities() const
{
	vector<Ability const*> abilities;
	abilities.push_back(&WarriorSmash);
	/*if( Level() > 2 )*/ abilities.push_back(&WarriorBuff);

	return abilities;
}

