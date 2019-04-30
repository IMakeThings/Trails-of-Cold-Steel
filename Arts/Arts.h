/*
 * Arts.h
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#ifndef ARTS_H_
#define ARTS_H_

#include <string>
#include <map>
#include <utility>
#include "Dice.h"
#include "Entity.h"

using Position = std::array<int, 2>;

class Art {

	//Art information
	std::string name;
	int EPCost;
	int castTime;
	int AoESize;
	std::string ID;

	int targetting;

	//Casting information
	int castingTimeRemaining;
	Position posAimed;
	Entity* entAimed;

public:
	Art(std::string n, int cp, int ct, int as) :
			name(n), EPCost(cp), castTime(ct), AoESize(as) {
		castingTimeRemaining = 0;
		entAimed = NULL;
		targetting = NULL;
	}

	//No new calls.
	virtual ~Art() {
	}

	//Casting functions
	void setCasting(Position a) {
		castingTimeRemaining = castTime;
		posAimed = a;
	}
	void setCasting(Entity* entity) {
		castingTimeRemaining = castTime;
		entAimed = entity;
	}
	bool castTick();
	Position getAimedPosition();

	//Getters
	int getAoESize() {
		return AoESize;
	}
	std::string getName() {
		return name;
	}
	int getEPCost() {
		return EPCost;
	}
	int getCastTime() {
		return castTime;
	}
	virtual int getBaseDamage() = 0;
	int getTargetting() {
		return (targetting);
	}
};

#endif /* ARTS_H_ */
