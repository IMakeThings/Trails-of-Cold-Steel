/*
 * Quartz.h
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#ifndef QUARTZ_H_
#define QUARTZ_H_

#include <string>
#include <array>
#include <vector>
#include "Arts.h"

using Stats = std::array<int, 11>;

class Quartz {
    Stats stats;
    std::string name;

protected:
    std::vector<Art*> arts;

public:
	virtual ~Quartz() {}
	Quartz(Stats const& s, std::string const &n):stats(s), name(n) {};

	std::string getQuartzName() {return name;}
	Stats getStatsModifier() {return stats;}
	std::vector<Art*> getArts() {return arts;}
};


#endif /* QUARTZ_H_ */
