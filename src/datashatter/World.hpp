#ifndef WORLD_HPP
#define WORLD_HPP

#include "common.hpp"

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

