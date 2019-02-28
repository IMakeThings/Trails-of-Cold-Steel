/*
 * DoubleKittyKick.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef DOUBLEKITTYKICK_H_
#define DOUBLEKITTYKICK_H_

#include "Crafts.h"

class DoubleKittyKick:public Craft {
	static const std::string name;
	static const int craftPoints;
	static const int AoESize;
	static const Targetting targetting;

public:
	DoubleKittyKick():Craft(name, craftPoints, AoESize, targetting) {}

	void displayHitDescription(Entity* hitter, Entity* hittee, int dmg);
	void displaySpecificCraftDescription();
	bool displayAfterHitDescription(Entity* hitter) {return false;}

	void craftAimedFunctions(Entity* user, Position aimed) {}

	~DoubleKittyKick() {}

	int getBaseDamage();
};



#endif /* DOUBLEKITTYKICK_H_ */
