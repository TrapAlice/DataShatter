#include "World.hpp"
#include "Character.hpp"

struct World::PrivateVariables{
	unique_ptr<Character> character;
};

World::World()
	: INIT_PRIVATE_VARIABLES
{
	m->character = unique_ptr<Character>(new Character());
}

World::~World(){}

Character& World::GetCharacter() { return *m->character.get(); }

