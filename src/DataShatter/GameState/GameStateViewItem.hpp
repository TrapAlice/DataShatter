#ifndef GAMESTATE_VIEWITEM_HPP
#define GAMESTATE_VIEWITEM_HPP

#include "GameState.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Item;

class State_ViewItem : public iGameState{
public:
	State_ViewItem(Terminal& t, GameStateStack& s, World& w, Item const& i);
	~State_ViewItem();
	void            Render();
	void            Update();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

