#include "GameStateSwapAbility.hpp"
#include "Character.hpp"
#include "World.hpp"
#include "Terminal.hpp"
#include "Ability/Ability.hpp"
#include "Spec.hpp"

PRIVATE_VARIABLES(State_SwapAbility){
	PrivateVariables(Character& c, unsigned pos, bool double_pop)
		: c(c)
		, pos(pos)
		, double_pop(double_pop)
	{}
	Character&      c;
	unsigned        pos;
	bool            double_pop;
	vector<Ability const*> specAbilities;
};

State_SwapAbility::State_SwapAbility(Terminal& t, GameStateStack& s, World& w,
                                     unsigned pos, bool double_pop)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES(w.GetCharacter(), pos, double_pop)
{
	m->specAbilities = m->c.GetSpec().GetAbilities();
}

State_SwapAbility::~State_SwapAbility(){}

void State_SwapAbility::Render()
{
	for( int x = 0; x < m->specAbilities.size(); ++x ){
		t.Printx(0, "[" << x+1 << "] - " << m->specAbilities[x]->Name());
	}
	t.Printx(0, "");
	t.Printx(0, "[A] Back");
}

void State_SwapAbility::Update()
{
	auto key = t.Key();
	int key_value = key - '1';
	if( key == 'a' ){
		s.pop();
		return;
	}
	if( key_value > m->specAbilities.size()
	||  key_value < 0 ) return;
	m->c.ReplaceAbility(m->pos, *m->specAbilities[key_value]);
	bool double_pop = m->double_pop;
	s.pop();
	if( double_pop ) s.pop();

}

