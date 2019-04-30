/*
 * DoubleKittyKick.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */
#include "DoubleKittyKick.h"

const std::string DoubleKittyKick::name = "Double Kitty Kick";
const int DoubleKittyKick::craftPoints = 0;
const int DoubleKittyKick::AoESize = 0;
const Targetting DoubleKittyKick::targetting = 0;

void DoubleKittyKick::displayHitDescription(Entity* hitter, Entity* hittee,
		int dmg) {
	std::cout << hitter->getName() << " used its foots to kick "
			<< hittee->getName() << " right in the mouf.\n\n";
	std::cout << hittee->getName() << " took " << dmg << " damage.\n";
}

void DoubleKittyKick::displaySpecificCraftDescription() {
	std::cout << "You just kick them.";
}

int DoubleKittyKick::getBaseDamage() {
	return Dice::rollDx(1, 6, 0);
}

