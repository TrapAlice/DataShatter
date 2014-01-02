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
#define INIT_PRIVATE_VARIABLES m(new PrivateVariables())
#define INIT_PRIVATE_VARIABLES_WITH(...) m(new PrivateVariables(__VA_ARGS__))

#endif
