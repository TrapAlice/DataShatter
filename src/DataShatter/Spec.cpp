#include "Spec.hpp"

PRIVATE_VARIABLES(Spec){
	unsigned        exp = 0;
	unsigned        level = 1;
};

Spec::Spec()
	: INIT_PRIVATE_VARIABLES()
{}

Spec::~Spec(){}

bool Spec::GainExp(unsigned amount)
{
	m->exp += amount;
	if( m->exp >= 50 * m->level ){
		m->level++;
		m->exp = 0;
		return true;
	}
	return false;
}

unsigned Spec::Exp() const { return m->exp; }
unsigned Spec::Level() const { return m->level; }

