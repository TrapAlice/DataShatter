#include "Game.hpp"
#include "Terminal.hpp"

struct Game::PrivateVariables{
	unique_ptr<Terminal> terminal;
};

Game::Game()
	: INIT_PRIVATE_VARIABLES 
{
	m->terminal = unique_ptr<Terminal>(new Terminal("Data Shatter"));
}

Game::~Game(){}

void Game::Run()
{
	while( !m->terminal->isClosed() ){
		m->terminal->Print("Hello World");
		m->terminal->Flush();
	}
}

