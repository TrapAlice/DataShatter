#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../common.hpp"

class Terminal;
class World;

class iGameState;
using GameStateStack = std::stack<unique_ptr<iGameState>>;

#define NEW_STATE(STATE, ...)\
	std::unique_ptr<State_##STATE>(new State_##STATE(t,s,w, ##__VA_ARGS__))

class iGameState{
public:
	iGameState(Terminal& t, GameStateStack& s, World& w)
		: t(t), s(s), w(w) {}
	virtual ~iGameState(){}
	virtual void    Render() = 0;
	virtual void    Update() = 0;
protected:
	Terminal&       t;
	GameStateStack& s;
	World&          w;
};

#endif

