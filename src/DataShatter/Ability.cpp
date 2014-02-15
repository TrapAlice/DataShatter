#include "Ability.hpp"
#include "Combatant.hpp"
#include "Condition.hpp"
#include <functional>

Condition Defending{ConditionType::On_defense,[](Combatant&,Combatant&, int& damage){
	damage = 0;
}, 250};

PRIVATE_VARIABLES(Ability){
	PrivateVariables(string const& name, double manaCost, int damage, unsigned time)
		: Name(name)
        , ManaCost(manaCost)
        , Damage(damage)
	, cooldown(time)
	{}
	string          Name;
	double          ManaCost;
    int             Damage;
	union{
		unsigned cooldown;
		unsigned delay;
	};
	std::function<void(Combatant&, Combatant&)> activate;
};

Ability::Ability(string const& name, int manaCost, int damage)
	: INIT_PRIVATE_VARIABLES(name, 3, damage, 1000)
{
	if(name == "Shield-Skill03"){
		m->activate = [](Combatant& attacker, Combatant& defender)
		                { attacker.GainCondition(Defending); };
		m->cooldown = 250;
		m->ManaCost = 0.5;
	}
}

Ability::Ability(Ability&& s) noexcept
	: INIT_PRIVATE_VARIABLES(s.m->Name, s.m->ManaCost, s.m->Damage, m->cooldown)
{

}

Ability::~Ability() noexcept
{}

void Ability::Activate(Combatant& attacker, Combatant& defender) const
{
	if( m->activate ){
		m->activate(attacker, defender);
	}
}

string const& Ability::Name() const { return m->Name; }
int Ability::ManaCost() const { return m->ManaCost; }
int Ability::Heat() const { return 1; }
int Ability::Damage() const { return m->Damage; }
unsigned Ability::Cooldown() const { return m->cooldown; }

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

