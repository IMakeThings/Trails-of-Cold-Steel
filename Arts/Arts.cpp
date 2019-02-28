/*
 * Arts.cpp
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#include "Arts.h"

std::map<std::string, Art&> artMap;


bool Art::castTick() {
	if(castingTimeRemaining > 0) {
		castingTimeRemaining -= 10;
		if(castingTimeRemaining <= 0) {
			castingTimeRemaining = 0;
			return (true);
		}
	}
	return (false);
}

Position Art::getAimedPosition() {
	if(targetting == 1 || targetting == 2 || targetting == 6) {
		return (posAimed);
	} else {
		return (entAimed->getPositions());
	}

}
