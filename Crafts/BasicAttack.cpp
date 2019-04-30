/*
 * BasicAttack.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#include "BasicAttack.h"

const std::string BasicAttack::name = "Basic Attack";
const int BasicAttack::craftPoints = 0;
const int BasicAttack::AoESize = 0;
const Targetting BasicAttack::targetting = 0;

void BasicAttack::displayHitDescription(Entity* hitter, Entity* hittee,
		int dmg) {
	std::cout << hitter->getName() << " slapped " << hittee->getName()
			<< " real good for " << dmg << " damage.\n";
}

int BasicAttack::getBaseDamage() {
	return 0;
}

