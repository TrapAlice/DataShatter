#ifndef GAMESTATE_VIEWABILITY_HPP
#define GAMESTATE_VIEWABILITY_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Ability;

class State_ViewAbility : public iGameState{
public:
	State_ViewAbility(Terminal& t, GameStateStack& s, World& w,
	                  unsigned pos, bool swappable);
	~State_ViewAbility();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

