#ifndef GAMESTATE_TOWN_HPP
#define GAMESTATE_TOWN_HPP

#include "GameState.hpp"

class State_Town : public iGameState{
public:
	State_Town(Terminal& t, GameStateStack& s, World& w);
	void            Render();
	void            Update();
};

#endif

