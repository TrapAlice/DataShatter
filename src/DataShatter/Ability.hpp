#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Combatant;

class Ability{
public:
	Ability(string const& name, int damage, double manaCost, double heat, unsigned cooldown);
	Ability(Ability&&) noexcept;
	~Ability() noexcept;
	string const&   Name() const;
	double          ManaCost() const;
    int             Heat() const;
    int             Damage() const;
	void            Activate(Combatant&, Combatant&) const;
	unsigned        Cooldown() const;
private:
	HAS_PRIVATE_VARIABLES;
};

extern const Ability Sword01;
extern const Ability Sword02;
extern const Ability Sword03;
extern const Ability SwordSword;
extern const Ability SwordShield;
extern const Ability Shield01;
extern const Ability Shield02;
extern const Ability Shield03;
extern const Ability ShieldSword;
extern const Ability ShieldShield;

#endif

