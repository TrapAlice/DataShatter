#ifndef GAME_HPP
#define GAME_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

class Game{
public:
	Game();
	~Game();
	void            Run();
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

