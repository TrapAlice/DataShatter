#ifndef COMMON_HPP
#define COMMON_HPP

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

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint;

#define DEBUG(...) std::cerr << __FILE__ << ":" << __LINE__ << " - " << __VA_ARGS__ << std::endl;

#define KEY(K) ((K == 1)? '1' :\
               (K == 2)? '2' :\
	       (K == 3)? '3' :\
	       (K == 4)? '4' :\
               (K == 5)? 'Q' :\
               (K == 6)? 'W' :\
	       (K == 7)? 'E' :\
	       (K == 8)? 'R' : ' ')

#endif
