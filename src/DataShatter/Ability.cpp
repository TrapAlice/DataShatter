#include "Ability.hpp"
#include "Combatant.hpp"
#include "Condition.hpp"
#include <functional>

Condition Defending{ConditionType::On_defense,[](Combatant&,Combatant&, int& damage){
	damage = 0;
}, 250};

PRIVATE_VARIABLES(Ability){
	PrivateVariables(string const& name, int damage, double manaCost, double heat, unsigned time)
		: Name(name)
		, Damage(damage)
		, ManaCost(manaCost)
		, Heat(heat)
		, cooldown(time)
	{}
	string          Name;
	int             Damage;
	double          ManaCost;
	double          Heat;
	union{
		unsigned cooldown;
		unsigned delay;
	};
	std::function<void(Combatant&, Combatant&)> activate;
};

Ability::Ability(string const& name, int damage, double manaCost, double heat, unsigned cooldown)
	: INIT_PRIVATE_VARIABLES(name, damage, manaCost, heat, cooldown)
{
	if(name == "Shield-Skill03"){
		m->activate = [](Combatant& attacker, Combatant& defender)
		                { attacker.GainCondition(Defending); };
	}
}

Ability::Ability(Ability&& s) noexcept
	: INIT_PRIVATE_VARIABLES(s.m->Name, s.m->Damage, s.m->ManaCost, s.m->Heat, m->cooldown)
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
double Ability::ManaCost() const { return m->ManaCost; }
int Ability::Heat() const { return 1; }
int Ability::Damage() const { return m->Damage; }
unsigned Ability::Cooldown() const { return m->cooldown; }

const Ability Sword01("Sword-Skill01", 5, 3, 0.1, 750);
const Ability Sword02("Sword-Skill02", 5, 3, 0.1, 750);
const Ability Sword03("Sword-Skill03", 5, 3, 0.1, 750);
const Ability SwordSword("SwordSword-Skill", 5, 3, 0.1, 750);
const Ability SwordShield("SwordShield-Skill", 5, 3, 0.1, 750);
const Ability Shield01("Shield-Skill01", 5, 3, 0.1, 750);
const Ability Shield02("Shield-Skill02", 5, 3, 0.1, 750);
const Ability Shield03("Shield-Skill03", 5, 3, 0.1, 750);
const Ability ShieldSword("ShieldSword-Skill", 5, 3, 0.1, 750);
const Ability ShieldShield("ShieldShield-Skill", 5, 3, 0.1, 750);

