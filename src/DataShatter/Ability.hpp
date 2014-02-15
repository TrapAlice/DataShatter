#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"
#include "AbilityId.hpp"

class Combatant;

class Ability{
public:
	Ability(string const& name, int manaCost, int damage);
	Ability(Ability&&) noexcept;
	~Ability() noexcept;
	string const&   Name() const;
    int             ManaCost() const;
    int             Heat() const;
    int             Damage() const;
	void            Activate(Combatant&, Combatant&) const;
	unsigned        Cooldown() const;
private:
	HAS_PRIVATE_VARIABLES;
};

class AbilityStore{
public:
	static void     LoadAbilities();
	static void     AddAbility(int id, Ability*);
	static Ability const& GetAbility(int id);
private:
	static std::array<shared_ptr<Ability>, AbilityId::TOTAL> mAbilities;
	static bool mAbilitiesLoaded;
};

#endif

