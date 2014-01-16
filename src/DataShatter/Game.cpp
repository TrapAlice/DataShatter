#include "Game.hpp"
#include "GameState/GameState.hpp"
#include "GameState/GameStateTown.hpp"
#include "Terminal.hpp"
#include "World.hpp"

PRIVATE_VARIABLES(Game){
	unique_ptr<Terminal> terminal;
	unique_ptr<World> world;
	stack<unique_ptr<iGameState>> stateStack;
};

Game::Game()
	: INIT_PRIVATE_VARIABLES()
{
	m->terminal = unique_ptr<Terminal>(new Terminal("Data Shatter"));
	m->world = unique_ptr<World>(new World());
	m->stateStack.push(unique_ptr<State_Town>(new State_Town(*m->terminal.get(), m->stateStack, *m->world.get())));
}

Game::~Game(){}

void Game::Run()
{
	while( !m->terminal->isClosed() ){
		iGameState* current_state = m->stateStack.top().get();
		current_state->Render();
		m->terminal->Flush();
		current_state->Update();
	}
}

