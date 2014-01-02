#include "GameStateBattle.hpp"

#include "../Terminal.hpp"
#include "../World.hpp"

struct State_Battle::PrivateVariables{
	int             enemyHp;
};

State_Battle::State_Battle(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES
{
}

State_Battle::~State_Battle(){}

void State_Battle::Render()
{
	t.Printx(0, "Hp  :");
	t.Printx(0, "Mana:");
	t.Printx(0, "Heat:");
	t.Print("");
	t.Printx(0, "EnemyHp: ");
	t.Print("");
	t.Printx(0, "[1] - Attack 1");
	t.Printx(0, "[2] - Attack 2");
	t.Printx(0, "[3] - Attack 3");
	t.Printx(0, "[4] - Attack 4");
}

void State_Battle::Update()
{
	switch( t.Key() ){
	}
}

