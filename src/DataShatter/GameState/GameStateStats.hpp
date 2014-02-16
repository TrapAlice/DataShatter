#ifndef GAMESTATE_STATS_HPP
#define GAMESTATE_STATS_HPP

#include "GameState.hpp"

class State_Stats : public iGameState{
public:
	State_Stats(Terminal& t, GameStateStack& s, World& w);
	~State_Stats();
	void            Render();
	void            Update();
private:
};

#endif

