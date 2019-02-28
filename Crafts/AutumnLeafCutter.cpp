/*
 * AutumnLeafCutter.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */
#include "AutumnLeafCutter.h"

const std::string AutumnLeafCutter::name = "Autumn Leaf Cutter";
const int AutumnLeafCutter::craftPoints = 20;
const int AutumnLeafCutter::AoESize = 2;
const int AutumnLeafCutter::unbalance = 10;
const Targetting AutumnLeafCutter::targetting = 1;
#include <iostream>

int AutumnLeafCutter::getBaseDamage() {
	return Dice::rollDx(1, 4, 0);
}

void AutumnLeafCutter::displayHitDescription(Entity* hitter, Entity* hittee, int dmg) {
	std::cout << hitter->getName() << " swung his sword around pretty well and hit " << hittee->getName() << " real good for " << dmg << " damage.\n";
}

bool AutumnLeafCutter::displayAfterHitDescription(Entity* hitter) {
	std::cout << hitter->getName() << " has been moved to " << hitter->getPositions()[0]+1 << "-" << hitter->getPositions()[1]+1 << " in the process.";
	return true;
}

void AutumnLeafCutter::displaySpecificCraftDescription() {
	std::cout << "1d4 DMG, Impede, Delay +1, Unbalance +10%";
}



void AutumnLeafCutter::craftAimedFunctions(Entity* user, Position aimed) {
	moveOpposite(user, aimed);
}

void AutumnLeafCutter::moveOpposite(Entity* entity, Position aimed) {
	Position moveTo;

	if(entity->getPositions()[0] > aimed[0]) {
		moveTo[0] = entity->getPositions()[0] - 2*entity->getXYdistanceToPoint(aimed)[0];
	} else if(entity->getPositions()[0] < aimed[0]) {
		moveTo[0] = entity->getPositions()[0] + 2*entity->getXYdistanceToPoint(aimed)[0];
	} else {
		moveTo[0] = entity->getPositions()[0];
	}
	if(entity->getPositions()[1] > aimed[1]) {
		moveTo[1] = entity->getPositions()[1] - 2*entity->getXYdistanceToPoint(aimed)[1];
	} else if(entity->getPositions()[0] < aimed[0]) {
		moveTo[1] = entity->getPositions()[1] + 2*entity->getXYdistanceToPoint(aimed)[1];
	} else {
		moveTo[1] = entity->getPositions()[1];
	}

	if(moveTo[0] < 0) {
		moveTo[0] = 0;
	} else if(moveTo[0] > 16) {
		moveTo[0] = 16;
	}
	if(moveTo[1] < 0) {
		moveTo[1] = 0;
	} else if(moveTo[1] > 16) {
		moveTo[1] = 16;
	}

	entity->moveEntity(moveTo);
}
