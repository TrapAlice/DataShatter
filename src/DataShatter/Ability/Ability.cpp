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

#define ABILITY(ID, NAME, POWER, MANACOST, HEAT, COOLDOWN) const Ability ID(NAME, POWER, MANACOST, HEAT, COOLDOWN);
       ABILITY(Sword01, "Sword-Skill01", 5, 3, 0.1, 750);
       ABILITY(Sword02, "Sword-Skill02", 10, 4, 0.1, 1000);
       ABILITY(Sword03, "Sword-Skill03", 15, 7, 0.3, 1200);
       ABILITY(SwordSword, "SwordSword-Skill", 20, 10, 0.5, 1200);
       ABILITY(SwordShield, "SwordShield-Skill", 15, 7, 0.2, 1000);
       ABILITY(Shield01, "Shield-Skill01", 3, 3, 0.1, 750);
       ABILITY(Shield02, "Shield-Skill02", 7, 3, 0.2, 1000);
       ABILITY(Shield03, "Shield-Skill03", 0, 0.5, 0.05, 250);
       ABILITY(ShieldSword, "ShieldSword-Skill", 13, 9, 0.3, 1000);
       ABILITY(ShieldShield, "ShieldShield-Skill", 0, 1, 0.1, 250);

       ABILITY(WarriorSmash, "WarriorSmash-Skill", 0, 1, 0.1, 250);
       ABILITY(WarriorBuff, "WarriorBuff-Skill", 0, 1, 0.1, 250);
#undef ABILITY

