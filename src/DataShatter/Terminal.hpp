#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "common.hpp"
#include "PimplMacro/PimplMacro.hpp"

#define Printxy(x, y, ...)  print(x, y) << __VA_ARGS__;
#define Printx(x, ...)      print(x) << __VA_ARGS__;
#define Printy(y, ...)      print(-1, y_) << __VA_ARGS__;
#define Print(...)          print() << __VA_ARGS__;


class Terminal{
public:
	struct RenderText{
		std::shared_ptr<std::ostringstream> message;
		Terminal& terminal;
		int x, y;

		RenderText(Terminal& t, int x, int y)
			: message(new std::ostringstream), terminal(t), x(x), y(y){}
		~RenderText() { terminal.p(x, y, *message.get()); }
		template <typename T>
		RenderText& operator<<( T const& value)
		{
			*message << value;
			return *this;
		}
	};
	Terminal(string const& title);
	~Terminal();
	void            Flush();
	bool            isClosed();
	RenderText      print(int x = -1, int y = -1);
	void            p(int x, int y, std::ostringstream& text);
	char            Key();
private:
	HAS_PRIVATE_VARIABLES;
	friend RenderText;
};

#endif

