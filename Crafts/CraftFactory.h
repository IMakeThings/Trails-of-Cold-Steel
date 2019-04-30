/*
 * CraftFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef CRAFTFACTORY_H_
#define CRAFTFACTORY_H_
#include "Crafts.h"
#include "AutumnLeafCutter.h"
#include "DoubleKittyKick.h"
#include "Motivate.h"
#include <functional>

class CraftFactory {
	static std::map<std::string, std::function<Craft*()>> craftMap;
	static bool loaded;

public:
	CraftFactory();

	static void loadCrafts();
	static Craft* getNewCraft(std::string ID) {
		return craftMap.find(ID)->second();
	}
	static std::map<std::string, std::function<Craft*()>> getCraftMap() {
		return craftMap;
	}
	static void regCraft(std::string ID, std::function<Craft*()> f) {
		craftMap[ID] = f;
	}

	static bool isLoaded() {
		return loaded;
	}
};

#endif /* CRAFTFACTORY_H_ */
