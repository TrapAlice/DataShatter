#ifndef GAMESTATE_ABILITIES_HPP
#define GAMESTATE_ABILITIES_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class State_Abilities : public iGameState{
public:
	State_Abilities(Terminal& t, GameStateStack& s, World& w);
	~State_Abilities();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

