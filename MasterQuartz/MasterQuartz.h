#ifndef MASTERQUARTZ_H
#define MASTERQUARTZ_H

#include <string>
#include <array>
#include "Arts.h"
#include "Entity.h"
#include <vector>

using Stats = std::array<int, 11>;

class MasterQuartz {
    Stats stats;
    std::string name;

protected:
    std::vector<Art*> arts;

public:
	virtual ~MasterQuartz() {}
	MasterQuartz(Stats const& s, std::string const &n):stats(s), name(n) {};

	virtual void masterQuartzOnDeathFunctions(Entity* user) = 0;

	std::string getMasterQuartzName() {return name;}
	Stats getStatsModifier() {return stats;}
	std::vector<Art*> getArts() {return arts;}
};















#endif
