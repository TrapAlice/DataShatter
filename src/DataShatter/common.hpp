#ifndef COMMON_HPP
#define COMMON_HPP

#pragma clang diagnostic ignored "-Wswitch"

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <stdexcept>
#include <memory>
#include <stack>
#include <map>
#include <chrono>
#include <array>

using std::string;
using std::vector;
using std::set;
using std::runtime_error;
using std::unique_ptr;
using std::shared_ptr;
using std::stack;
using std::map;
using std::ostringstream;

typedef std::chrono::time_point<std::chrono::system_clock> Time;

#define DEBUG(...) std::cerr << __FILE__ << ":" << __LINE__ << " - " << __VA_ARGS__ << std::endl;

#define HAS_PRIVATE_VARIABLES struct PrivateVariables; unique_ptr<PrivateVariables> m;
#define PRIVATE_VARIABLES(CLASS, ...)\
	struct CLASS::PrivateVariables{\
		__VA_ARGS__\
	};
#define INIT_PRIVATE_VARIABLES(...) m(new PrivateVariables(__VA_ARGS__))

#define HAS_PRIVATE_FUNCTIONS class PrivateFunctions; friend PrivateFunctions;
#define PRIVATE_FUNCTIONS(CLASS, ...)\
	using PrivateClassType = CLASS;\
	class CLASS::PrivateFunctions{\
	public:\
		__VA_ARGS__\
	};
#define PRIVATE_FUNCTION_DECLARE(RETURN, NAME, ...)\
	static RETURN NAME(PrivateClassType* This, ##__VA_ARGS__)
#define PRIVATE_FUNCTION_DEFINE(...) { __VA_ARGS__ }
#define PRIVATE(FUNCTION, ...) PrivateFunctions::FUNCTION(this, ##__VA_ARGS__);

#endif
