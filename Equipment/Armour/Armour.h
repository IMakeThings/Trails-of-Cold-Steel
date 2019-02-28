#ifndef ARMOUR_H
#define ARMOUR_H
#include "Equipment.h"



//Defining what a weapon is and all types of weapons so they get loaded all at once.
class Armour: public Equipment {
public:
    Armour(Stats const& s, std::string const &n) : Equipment(s, n) {}
};

class LeatherJacket: public Armour {
    static const Stats stats;
    static const std::string name;

public:
    LeatherJacket() : Armour(stats, name) {}
};

#endif

