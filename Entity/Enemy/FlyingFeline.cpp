/*
 * FlyingFeline.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */
#include "FlyingFeline.h"

const Stats FlyingFeline::baseStats = {6,0,10,16,0,9,1,0,0,1,1};
const std::string FlyingFeline::name = "Flying Feline";
const UnbalanceEfficacy FlyingFeline::efficacy = {2, 2, 2, 3};
int FlyingFeline::count = 0;
const std::string FlyingFeline::representation = "F";

FlyingFeline::FlyingFeline(Position position):Enemy(baseStats, name, position, efficacy, representation) {
	addCraft(new DoubleKittyKick());
	FlyingFeline::count++;

	if (count > 9) {
		count = 1;
	}

	const std::string representation;
	setName(getName() + " " + std::to_string(count));
	setRepresentation(getRepresentation() + std::to_string(count));
}

void FlyingFeline::takeTurn() {
	Entity* closestCharacter = findClosestCharacterInRange();


	if(getDistanceToPoint(findClosestPositionToPointInRange(closestCharacter->getPositions())) >= getRNG()) {
		if(closestCharacter->getPositions()[0] > getPositions()[0] && abs(closestCharacter->getPositions()[0] - getPositions()[0]) > 1) {
			moveEntity({getPositions()[0] + getTotalStats()[9], getPositions()[1]});
		} else if(abs(closestCharacter->getPositions()[0] - getPositions()[0]) > 1) {
			moveEntity({getPositions()[0] - getTotalStats()[9], getPositions()[1]});
		} else if(closestCharacter->getPositions()[1] > getPositions()[1]) {
			moveEntity({getPositions()[0], getPositions()[1] + getTotalStats()[9]});
		} else {
			moveEntity({getPositions()[0], getPositions()[1] - getTotalStats()[9]});
		}
		Map::update();
		Map::display();
		std::cout << getName() << " moved to " << getPositions()[0]+1 << "-" << getPositions()[1]+1 << std::endl;
		enterPause();
	} else {
		useCraft(getCrafts()[0], closestCharacter);
	}
	return;
}



