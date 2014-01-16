#ifndef GAMESTATE_BATTLE_HPP
#define GAMESTATE_BATTLE_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class State_Battle : public iGameState{
public:
	State_Battle(Terminal& t, GameStateStack& s, World& w);
	~State_Battle();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

