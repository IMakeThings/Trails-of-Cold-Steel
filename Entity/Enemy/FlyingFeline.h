/*
 * FlyingFeline.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef FLYINGFELINE_H_
#define FLYINGFELINE_H_

#include "Enemy.h"
#include "DoubleKittyKick.h"

class FlyingFeline:public Enemy {
	static const Stats baseStats;
	static const std::string name;
	static const UnbalanceEfficacy efficacy;
	static int count;
	static const std::string representation;


public:
	FlyingFeline(Position position);

	int getAttackModifier() {return 0;}
	int getArtModifier() {return 0;}

	void takeTurn();

	int getCount() {return count;}
};



#endif /* FLYINGFELINE_H_ */
