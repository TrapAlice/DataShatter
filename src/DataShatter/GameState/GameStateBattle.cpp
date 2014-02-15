#include "GameStateBattle.hpp"

#include "Ability.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "Terminal.hpp"
#include "World.hpp"

PRIVATE_VARIABLES(State_Battle){
	Enemy           enemy;
};

State_Battle::State_Battle(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES()
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
	t.Printx(0, "EnemyHp: " << m->enemy.Hp());
	t.Print("");

	auto abilities = c.GetAbilities();
	for( int x = 0; x < 4; ++x ){
		t.Printx(0, "[" << x << "] - " << abilities[x]->Name());
	}
}

void State_Battle::Update()
{
	Character& c = w.GetCharacter();
	auto key = t.Key();
	switch( key ){
		case '1':
		case '2':
		case '3':
		case '4':
			c.UseSkill(key - 48, m->enemy);
			break;
	}
	c.GainMana(0.2);
	m->enemy.Update(c);
	c.Update(m->enemy);
	if( m->enemy.Hp() <= 0 ){
		c.BattleEnd();
		s.pop();
	}
}

