/*
 * MasterQuartzFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef MASTERQUARTZFACTORY_H_
#define MASTERQUARTZFACTORY_H_

#include "MasterQuartz.h"
#include "ForceLvl1.h"
#include <functional>
#include <map>

class MasterQuartzFactory {
	static std::map<std::string, std::function<MasterQuartz*()>> masterQuartzMap;
	static bool loaded;

public:
	MasterQuartzFactory();

	static void loadMasterQuartz();
	static MasterQuartz* getNewMasterQuartz(std::string ID) {return masterQuartzMap.find(ID)->second();}
	static std::map<std::string, std::function<MasterQuartz*()>> getMasterQuartzMap() {return masterQuartzMap;}
	static void regMasterQuartz(std::string ID, std::function<MasterQuartz*()> f) {masterQuartzMap[ID] = f;}

	static bool isLoaded() {return loaded;}
};



#endif /* MASTERQUARTZFACTORY_H_ */
