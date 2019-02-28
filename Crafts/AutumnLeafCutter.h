/*
 * AutumnLeafCutter.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#ifndef AUTUMNLEAFCUTTER_H_
#define AUTUMNLEAFCUTTER_H_

#include "Crafts.h"

class AutumnLeafCutter:public Craft {
	static const std::string name;
	static const int craftPoints;
	static const int AoESize;
	static const int unbalance;
	static const Targetting targetting;

public:
	AutumnLeafCutter():Craft(name, craftPoints, AoESize, targetting, unbalance) {}

	~AutumnLeafCutter() {}

	void displayHitDescription(Entity* hitter, Entity* hittee, int dmg);
	bool displayAfterHitDescription(Entity* hitter);
	void displaySpecificCraftDescription();

	void craftAimedFunctions(Entity* user, Position aimed);

	void moveOpposite(Entity* entity, Position aimed);

	int getBaseDamage();

	int getAoESize() {return AoESize;}
};



#endif /* AUTUMNLEAFCUTTER_H_ */
