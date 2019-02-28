#ifndef WEAPON_H
#define WEAPON_H
#include "Equipment.h"

//Defining what a weapon is and all types of weapons so they get loaded all at once.
//Defining an empty weapon class so that I can keep track of how many of each type a character has.
class Weapon:public Equipment {
public:
	Weapon(Stats const& s, std::string const &n) : Equipment(s, n) {}
};









class Kazekiri:public Weapon {
    static const Stats stats;
    static const std::string name;

public:
    Kazekiri () : Weapon(stats, name) {}
};


#endif
