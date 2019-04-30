/*
 * ForceLvl1.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef FORCELVL1_H_
#define FORCELVL1_H_

#include "MasterQuartz.h"
#include "FireBolt.h"

class Forcelvl1: public MasterQuartz {
	static const Stats stats;
	static const std::string name;

public:
	Forcelvl1() :
			MasterQuartz(stats, name) {
		arts.push_back(new FireBolt());
	}

	void masterQuartzOnDeathFunctions(Entity* user);

	void gainCPonKill(Entity* user);
};

#endif /* FORCELVL1_H_ */
