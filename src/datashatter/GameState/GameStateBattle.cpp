#include "GameStateBattle.hpp"

#include "../Character.hpp"
#include "../Terminal.hpp"
#include "../World.hpp"

struct State_Battle::PrivateVariables{
	int             enemyHp = 100;
};

State_Battle::State_Battle(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES
{
}

State_Battle::~State_Battle(){}

void State_Battle::Render()
{
	Character& c = w.GetCharacter();
	t.Printx(0, "Hp  : " << c.Hp() << "/" << c.MaxHp());
	t.Printx(0, "Mana: " << c.Mana() << "/" << c.MaxMana());
	t.Printx(0, "Heat: " << c.Heat() << "/" << 100);
	t.Print("");
	t.Printx(0, "EnemyHp: " << m->enemyHp);
	t.Print("");
	t.Printx(0, "[1] - Attack 1");
	t.Printx(0, "[2] - Attack 2");
	t.Printx(0, "[3] - Attack 3");
	t.Printx(0, "[4] - Attack 4");
}

void State_Battle::Update()
{
	Character& c = w.GetCharacter();
	switch( t.Key() ){
		case '1':
			if( c.Mana() >= 5){
				c.UseMana(5);
				c.GenerateHeat(2);
				m->enemyHp -= 10;
			}
			break;
	}
	c.GainMana(0.2);
	c.LoseHeat(0.1);
	if( m->enemyHp <= 0 ){
		s.pop();
	}
}

