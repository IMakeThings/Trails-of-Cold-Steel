/*
 * QuartzFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef QUARTZFACTORY_H_
#define QUARTZFACTORY_H_

#include "Quartz.h"
#include "Attack1.h"
#include <functional>
#include <map>

class QuartzFactory {
	static std::map<std::string, std::function<Quartz*()>> quartzMap;
	static bool loaded;

public:
	QuartzFactory();

	static void loadQuartz();
	static Quartz* getNewQuartz(std::string ID) {
		return quartzMap.find(ID)->second();
	}
	static std::map<std::string, std::function<Quartz*()>> getQuartzMap() {
		return quartzMap;
	}
	static void regQuartz(std::string ID, std::function<Quartz*()> f) {
		quartzMap[ID] = f;
	}

	static bool isLoaded() {
		return loaded;
	}
};

#endif /* QUARTZFACTORY_H_ */
