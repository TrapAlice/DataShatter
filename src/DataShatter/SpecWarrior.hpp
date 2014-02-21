#ifndef SPEC_WARRIOR_HPP
#define SPEC_WARRIOR_HPP

#include "Spec.hpp"

class Spec_Warrior : public Spec{
public:
	Spec_Warrior();
	~Spec_Warrior();

	string          Name() const;
	vector<Ability const*> GetAbilities() const;
private:
};

#endif

