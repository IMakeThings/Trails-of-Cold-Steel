/*
 * MasterQuartzFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "MasterQuartzFactory.h"

std::map<std::string, std::function<MasterQuartz*()>> MasterQuartzFactory::masterQuartzMap;
bool MasterQuartzFactory::loaded = false;


MasterQuartzFactory::MasterQuartzFactory() {
	return;
}

void MasterQuartzFactory::loadMasterQuartz() {
	loaded = true;
	masterQuartzMap["001MQ"] = []() -> MasterQuartz* {return new Forcelvl1();};
}





