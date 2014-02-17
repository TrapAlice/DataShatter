#ifndef SPEC_HPP
#define SPEC_HPP

#include "PimplMacro/PimplMacro.hpp"
#include "common.hpp"

class Spec{
public:
	Spec();
	~Spec();

	bool            GainExp(unsigned amount);
	unsigned        Exp() const;
	virtual string  Name() const = 0;
	unsigned        Level() const;
private:
	HAS_PRIVATE_VARIABLES;
};

#endif

