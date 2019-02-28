/*
 * FireBolt.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#include "FireBolt.h"

const std::string FireBolt::name = "Fire Bolt";
const int FireBolt::EPCost = 2;
const int FireBolt::castTime = 300;
const int FireBolt::AoESize = 0;



int FireBolt::getBaseDamage() {
	return Dice::rollDx(1, 4, 0);
}

