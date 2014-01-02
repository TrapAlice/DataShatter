#ifndef GAME_HPP
#define GAME_HPP

#include "common.hpp"

class Game{
public:
	Game();
	void            Run();
private:
	class PrivateVariables;
	unique_ptr<PrivateVariables> m;
};

#endif

