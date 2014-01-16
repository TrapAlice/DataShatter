#ifndef WORLD_HPP
#define WORLD_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Character;

class World{
public:
	World();
	~World();
	Character& GetCharacter();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

