#ifndef GAMESTATE_INVENTORY_HPP
#define GAMESTATE_INVENTORY_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class State_Inventory : public iGameState{
public:
	State_Inventory(Terminal& t, GameStateStack& s, World& w);
	~State_Inventory();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

