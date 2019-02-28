#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

#include <array>
using Stats = std::array<int, 11>;

class Equipment {
    Stats stats;
    std::string name;

public:
    ~Equipment() {}
    std::string getName() {return name;}
    void setName(std::string n) {name = n;}

    Stats getStatsModifier() {return stats;}
    void setStatsModifier(Stats &s) {stats = s;}

    Equipment(Stats const& s, std::string const &n):stats(s), name(n) {};
};




#endif
