#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"
#include "AbilityId.hpp"

class Ability{
public:
	Ability(string const& name);
	Ability(Ability&&) noexcept;
	~Ability() noexcept;
	string const&   Name() const;
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

