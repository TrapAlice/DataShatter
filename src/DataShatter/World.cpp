#include "World.hpp"
#include "Character.hpp"

#include "Item.hpp"
#include "ItemData.hpp"
#include "Equipment.hpp"

PRIVATE_VARIABLES(World){
	unique_ptr<Character> character;
};

World::World()
	: INIT_PRIVATE_VARIABLES()
{
	m->character = unique_ptr<Character>(new Character());
	m->character->GiveItem({ItemDataStore::GetData(0)});
	m->character->GiveItem({ItemDataStore::GetData(1)});
	m->character->Equip(m->character->Items()[0]);
	m->character->Equip(m->character->Items()[1], LEFT_HAND);
}

World::~World(){}

Character& World::GetCharacter() { return *m->character.get(); }

