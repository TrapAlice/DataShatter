#include "GameStateBattleEnd.hpp"
#include "Terminal.hpp"
#include "World.hpp"
#include "Character.hpp"

PRIVATE_VARIABLES(State_BattleEnd){
	bool hasLeveled = false;
};

State_BattleEnd::State_BattleEnd(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES()
{
	auto& c = w.GetCharacter();
	if( c.GainExp(50) ){
		m->hasLeveled = true;
	}
}

State_BattleEnd::~State_BattleEnd(){}

void State_BattleEnd::Render()
{
	t.Printx(0, "You win!");
	t.Printx(0, "You get 10exp");
	if( m->hasLeveled ){
		t.Printx(0, "You have leveled!");
	}
}

void State_BattleEnd::Update()
{
	auto key = t.Key();
	if( key ) s.pop();
}
