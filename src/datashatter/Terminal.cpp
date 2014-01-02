#include "Terminal.hpp"
#include "libtcod.hpp"

struct Terminal::PrivateVariables{
	PrivateVariables()
		: line(0)
		, x(0)
	{}
	unique_ptr<TCODConsole> console;
	int                line;
	int                x;
};

namespace{
	int countNewLines(std::string const& str)
	{
		int count = 0;
		for( size_t offset = str.find("\n"); offset != std::string::npos;
			offset = str.find("\n", offset + str.length())){
			count++;
		}
		return count;
	}
}

Terminal::Terminal(string const& title)
	: INIT_PRIVATE_VARIABLES 
{
	m->console = std::unique_ptr<TCODConsole>(new TCODConsole(80, 25));
	TCODConsole::setCustomFont("terminal.png", TCOD_FONT_LAYOUT_ASCII_INROW, 0, 0);
	TCODConsole::initRoot(80, 25, title.c_str(), false);
}

Terminal::~Terminal(){}

void Terminal::Flush()
{
	TCODConsole::root->clear();
	TCODConsole::blit(m->console.get(), 0, 0, 80, 25, TCODConsole::root, 0, 0);
	TCODConsole::flush();
	m->console->clear();
	m->line = 0;
	m->x = 0;
}

bool Terminal::isClosed()
{
	return TCODConsole::isWindowClosed();
}

char Terminal::Key()
{
	TCOD_key_t key;
	TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
	return key.c;
}

Terminal::RenderText Terminal::print(int x, int y)
{
	return RenderText(*this, x, y);
}

void Terminal::p(int x, int y, std::ostringstream& text)
{
	if( x >= 0) m->x = x;
	if( y >= 0) m->line = y;
	m->console->print(m->x, m->line, text.str().c_str());
	m->x += text.str().length();
	int newLines = countNewLines(text.str());
	if( newLines ){
		m->line += newLines;
		unsigned last = text.str().find_last_of("\n");
		m->x = text.str().length() - last - 1;
	}
}

