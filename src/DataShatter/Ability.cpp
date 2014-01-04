#include "Ability.hpp"

struct Ability::PrivateVariables{
	PrivateVariables(string const& name)
		: Name(name)
	{}
	string          Name;
};

Ability::Ability(string const& name)
	: INIT_PRIVATE_VARIABLES_WITH(name)
{}

Ability::Ability(Ability&& s) noexcept
	: INIT_PRIVATE_VARIABLES_WITH(s.m->Name)
{

}

Ability::~Ability() noexcept
{}

string const& Ability::Name() const { return m->Name; }

void AbilityStore::LoadAbilities()
{
#define ABILITY(ID, NAME) AddAbility(ID, new Ability(NAME));
	ABILITY(Sword01, "Sword-Skill01");
	ABILITY(Sword02, "Sword-Skill02");
	ABILITY(Shield03, "Shield-Skill03");
	ABILITY(SwordShield, "SwordShield-Skill");
#undef ABILITY
	mAbilitiesLoaded = true;
}

void AbilityStore::AddAbility(int id, Ability* ability)
{
	mAbilities[id].reset(ability);
}

Ability const& AbilityStore::GetAbility(int id)
{
	if( !mAbilitiesLoaded ) LoadAbilities();
	return *mAbilities.at(id).get();
}

std::array<shared_ptr<Ability>, AbilityId::TOTAL> AbilityStore::mAbilities;
bool AbilityStore::mAbilitiesLoaded = false;

