#ifndef SHOES_H
#define SHOES_H
#include "Equipment.h"

//Defining what a weapon is and all types of weapons so they get loaded all at once.
class Shoes: public Equipment {
public:
	Shoes(Stats const& s, std::string const &n) :
			Equipment(s, n) {
	}
};

class LeatherShoes: public Shoes {
	static const Stats stats;
	static const std::string name;

public:
	LeatherShoes() :
			Shoes(stats, name) {
	}
};

#endif
