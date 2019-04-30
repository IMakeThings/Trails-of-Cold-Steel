/*
 * Motivate.h
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */

#ifndef MOTIVATE_H_
#define MOTIVATE_H_

#include "Crafts.h"

class Motivate: public Craft {
	static const std::string name;
	static const int craftPoints;
	static const int AoESize;
	static const int unbalance;
	static const Targetting targetting;

public:
	Motivate() :
			Craft(name, craftPoints, AoESize, targetting, unbalance) {
	}

	~Motivate() {
	}

	void displayHitDescription(Entity* hitter, Entity* hittee, int dmg);
	void displaySpecificCraftDescription();

	void craftOnHitFunctions(Entity* entity);

	void giveCP(Entity* character) {
		character->setCP(character->getCP() + 10);
	}

	void STRbuff(Entity* character);

	int getBaseDamage();

	int getAoESize() {
		return AoESize;
	}
};

#endif /* MOTIVATE_H_ */
