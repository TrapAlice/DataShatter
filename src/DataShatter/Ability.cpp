#include "Ability.hpp"

PRIVATE_VARIABLES(Ability){
	PrivateVariables(string const& name, int manaCost, int damage)
		: Name(name)
        , ManaCost(manaCost)
        , Damage(damage)
	{}
	string          Name;
	int             ManaCost;
    int             Damage;
};

Ability::Ability(string const& name, int manaCost, int damage)
	: INIT_PRIVATE_VARIABLES(name, 3, damage)
{}

Ability::Ability(Ability&& s) noexcept
	: INIT_PRIVATE_VARIABLES(s.m->Name, s.m->ManaCost, s.m->Damage)
{

}

Ability::~Ability() noexcept
{}

string const& Ability::Name() const { return m->Name; }
int Ability::ManaCost() const { return m->ManaCost; }
int Ability::Heat() const { return 1; }
int Ability::Damage() const { return m->Damage; }

void AbilityStore::LoadAbilities()
{
#define ABILITY(ID, NAME, DAMAGE) AddAbility(ID, new Ability(NAME, 3, DAMAGE));
	ABILITY(Sword01, "Sword-Skill01", 5);
	ABILITY(Sword02, "Sword-Skill02", 10);
	ABILITY(Sword03, "Sword-Skill03", 15);
	ABILITY(SwordSword, "SwordSword-Skill", 20);
	ABILITY(SwordShield, "SwordShield-Skill", 15);
	ABILITY(Shield01, "Shield-Skill01", 3);
	ABILITY(Shield02, "Shield-Skill02", 7);
	ABILITY(Shield03, "Shield-Skill03", 0);
	ABILITY(ShieldSword, "ShieldSword-Skill", 13);
	ABILITY(ShieldShield, "ShieldShield-Skill", 0);
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

