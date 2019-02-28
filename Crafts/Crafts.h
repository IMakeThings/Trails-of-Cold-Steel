#ifndef CRAFTS_H
#define CRAFTS_H

#include <string>
#include <iostream>
#include "Entity.h"
#include "Dice.h"
using Targetting = int;

class Craft {
	std::string name;
	int craftPoints;
	int unbalance;
	int AoESize;
	Targetting targetting;

public:
	Craft(std::string n, int cp, int as, int tar) {name=(n); craftPoints=(cp); AoESize=(as); targetting=(tar); unbalance=(0);}
	Craft(std::string n, int cp, int as, int tar, int u) {name = n; craftPoints = cp; AoESize = as; targetting=tar; unbalance=u;}

	virtual ~Craft() {}

	std::string getName() {return name;}
	int getCraftPoints() {return craftPoints;}
	int getAoESize() {return AoESize;}
	int getUnbalance() {return unbalance;}
	Targetting getTargetting() {return targetting;}

	virtual void displayHitDescription(Entity* hitter, Entity* hittee, int dmg) = 0;
	virtual bool displayAfterHitDescription(Entity* hitter) {return false;}
	virtual void displaySpecificCraftDescription() = 0;
	void displayCraftDescription();


	virtual void craftAimedFunctions(Entity* user, Position aimed) {};
	virtual void craftOnHitFunctions(Entity* entity) {};

	virtual int getBaseDamage() = 0;
};

#endif
