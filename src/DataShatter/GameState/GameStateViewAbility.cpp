#include "GameStateViewAbility.hpp"
#include "Terminal.hpp"
#include "World.hpp"
#include "Character.hpp"
#include "Ability.hpp"
#include "GameStateSwapAbility.hpp"

PRIVATE_VARIABLES(State_ViewAbility){
	PrivateVariables(unsigned pos, Ability const& a, bool swappable)
		: pos(pos)
		, ability(a)
		, swappable(swappable)
	{}
	unsigned        pos;
	Ability const&  ability;
	bool            swappable;
};

State_ViewAbility::State_ViewAbility(Terminal& t, GameStateStack& s,
                                     World& w, unsigned pos, bool swappable)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES(pos, *w.GetCharacter().GetAbilities()[pos-1], swappable)
{}

State_ViewAbility::~State_ViewAbility(){}

void State_ViewAbility::Render()
{
	t.Printx(0, m->ability.Name());
	if( m->swappable ) t.Printx(0, "[S] Swap ability");
	t.Printx(0, "");
	t.Printx(0, "[A] Back");
}

void State_ViewAbility::Update()
{
	switch( t.Key() ){
		case 'a':
			s.pop();
			break;
		case 's':
			s.push(NEW_STATE(SwapAbility, m->pos, true));
			break;
	}
}
