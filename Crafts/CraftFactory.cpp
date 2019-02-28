/*
 * CraftFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "CraftFactory.h"

std::map<std::string, std::function<Craft*()>> CraftFactory::craftMap;
bool CraftFactory::loaded = false;


CraftFactory::CraftFactory() {
	return;
}

void CraftFactory::loadCrafts() {
	loaded = true;
	craftMap["AutumnLeafCutter"] = []() -> Craft* {return new AutumnLeafCutter();};
	craftMap["DoubleKittyKick"] = []() -> Craft* {return new DoubleKittyKick();};
	craftMap["Motivate"] = []() -> Craft* {return new Motivate();};
}





