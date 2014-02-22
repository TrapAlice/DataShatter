#ifndef GAMESTATE_SWAPABILITY_HPP
#define GAMESTATE_SWAPABILITY_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class State_SwapAbility : public iGameState{
public:
	State_SwapAbility(Terminal& t, GameStateStack& s, World& w, unsigned pos,
	                  bool double_pop = false);
	~State_SwapAbility();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

