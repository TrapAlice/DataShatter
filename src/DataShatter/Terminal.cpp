#include "Terminal.hpp"
#include "libtcod.hpp"

PRIVATE_VARIABLES(Terminal){
	unique_ptr<TCODConsole> console;
	int                line = 0;
	int                x = 0;
};

Terminal::Terminal(string const& title)
	: INIT_PRIVATE_VARIABLES()
{
	m->console = std::unique_ptr<TCODConsole>(new TCODConsole(80, 25));
	TCODConsole::setCustomFont("terminal.png", TCOD_FONT_LAYOUT_ASCII_INROW, 0, 0);
	TCODConsole::initRoot(80, 25, title.c_str(), false);
	TCODSystem::setFps(30);
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
	TCOD_key_t key = TCODConsole::checkForKeypress(TCOD_KEY_PRESSED);
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
	m->console->print(m->x, m->line, "%c%s%c", TCOD_COLCTRL_1, text.str().c_str(), TCOD_COLCTRL_STOP);
	m->line++;
}

void Terminal::SetColour(Colour colour)
{
	switch( colour ){
	case Colour::White:
		TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::white,TCODColor::black);
		break;
	case Colour::Green:
		TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::green,TCODColor::black);
		break;
	case Colour::Orange:
		TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::orange,TCODColor::black);
		break;
	case Colour::Red:
		TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::red,TCODColor::black);
		break;
	case Colour::Gray:
		TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::grey,TCODColor::black);
		break;
	}
}

