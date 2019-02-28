/*
 * FireBolt.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef FIREBOLT_H_
#define FIREBOLT_H_

#include "Arts.h"

class FireBolt:public Art {
	static const std::string name;
	static const int EPCost;
	static const int castTime;
	static const int AoESize;

public:
	FireBolt():Art(name, EPCost, castTime, AoESize) {}

	~FireBolt() {}

	int getBaseDamage();
};

#endif /* FIREBOLT_H_ */
