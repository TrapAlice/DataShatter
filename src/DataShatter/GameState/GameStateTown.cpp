#include "GameStateTown.hpp"
#include "GameStateBattle.hpp"
#include "Terminal.hpp"
#include "World.hpp"

State_Town::State_Town(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
{}

void State_Town::Render()
{
	t.Printx(0, "You are in a town and stuff");
	t.Printx(0, "");
	t.Printx(0, "[1] Leave the town");
	t.Printx(0, "[2] Look at the shops");
	t.Printx(0, "[3] Look at yourself");
}

void State_Town::Update()
{
	switch( t.Key() ){
		case '1':
			s.push(NEW_STATE(Battle));
			break;
	}
}
