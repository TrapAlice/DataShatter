#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "common.hpp"
#include "Combatant.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Enemy : public Combatant{
public:
	Enemy();
	~Enemy();

private:
	HAS_PRIVATE_VARIABLES;
};

#endif
