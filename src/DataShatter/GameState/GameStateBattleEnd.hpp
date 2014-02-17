#ifndef GAMESTATE_BATTLEEND_HPP
#define GAMESTATE_BATTLEEND_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class State_BattleEnd : public iGameState{
public:
	State_BattleEnd(Terminal& t, GameStateStack& s, World& w);
	~State_BattleEnd();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

