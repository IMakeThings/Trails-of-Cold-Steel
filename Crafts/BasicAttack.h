/*
 * BasicAttack.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef BASICATTACK_H_
#define BASICATTACK_H_

#include "Crafts.h"

class BasicAttack: public Craft {
	static const std::string name;
	static const int craftPoints;
	static const int AoESize;
	static const Targetting targetting;

public:
	BasicAttack() :
			Craft(name, craftPoints, AoESize, targetting) {
	}

	void displayHitDescription(Entity* hitter, Entity* hittee, int dmg);
	void displaySpecificCraftDescription() {
		std::cout << "The big spank";
	}

	void craftAimedFunctions(Entity* user, Position aimed) {
	}

	~BasicAttack() {
	}

	int getBaseDamage();
};

#endif /* BASICATTACK_H_ */
