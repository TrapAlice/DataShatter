#include "GameStateAbilities.hpp"

#include "Terminal.hpp"
#include "World.hpp"
#include "Character.hpp"
#include "Ability/Ability.hpp"
#include "GameStateViewAbility.hpp"
#include "GameStateSwapAbility.hpp"

PRIVATE_VARIABLES(State_Abilities){
};

State_Abilities::State_Abilities(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES()
{
}

State_Abilities::~State_Abilities(){}

void State_Abilities::Render()
{
	Character& c = w.GetCharacter();
	auto abilities = c.GetAbilities();
	for( int x = 0; x < 8; ++x ){
		char key = KEY(x+1);
		if( abilities[x] ){
			t.Printx(0, "[" << key << "] - " << abilities[x]->Name());
		} else {
			t.Printx(0, "[" << key << "] ---");
		}
	}
	t.Printx(0, "");
	t.Printx(0, "[A] Back");
}

void State_Abilities::Update()
{
	Character& c = w.GetCharacter();
	auto abilities = c.GetAbilities();
	auto key = t.Key();
	switch( key )
	{
		case 'a':
			s.pop();
			break;
		case '1':
		case '2':
		case '3':
		case '4':
			s.push(NEW_STATE(ViewAbility, key - '1', false));
			break;
#define VIEWIFVALID(ABILITYID)\
	if( !abilities[ABILITYID-1] )\
		s.push(NEW_STATE(SwapAbility, ABILITYID));\
	else\
		s.push(NEW_STATE(ViewAbility, ABILITYID,true));\
	break;
		case 'q':
			VIEWIFVALID(5);
		case 'w':
			VIEWIFVALID(6);
		case 'e':
			VIEWIFVALID(7);
		case 'r':
			VIEWIFVALID(8);
#undef VIEWIFVALID
	}
}

