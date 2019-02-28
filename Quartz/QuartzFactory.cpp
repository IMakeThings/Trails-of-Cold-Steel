/*
 * QuartzFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "QuartzFactory.h"

std::map<std::string, std::function<Quartz*()>> QuartzFactory::quartzMap;
bool QuartzFactory::loaded = false;


QuartzFactory::QuartzFactory() {
	return;
}

void QuartzFactory::loadQuartz() {
	loaded = true;
	quartzMap["001Q"] = []() -> Quartz* {return new Attack1();};
}





