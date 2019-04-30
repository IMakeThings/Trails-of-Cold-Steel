/*
 * EnemyFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef ENEMYFACTORY_H_
#define ENEMYFACTORY_H_

#include "Enemy.h"
#include "FlyingFeline.h"
#include <functional>

class EnemyFactory {
	static std::map<std::string, std::function<Enemy*()>> enemyMap;
	static bool loaded;

public:
	EnemyFactory();

	static void loadEnemies();
	static Enemy* getNewEnemy(std::string ID) {
		return enemyMap.find(ID)->second();
	}
	static std::map<std::string, std::function<Enemy*()>> getEnemyMap() {
		return enemyMap;
	}
	static void regEnemy(std::string ID, std::function<Enemy*()> f) {
		enemyMap[ID] = f;
	}

	static bool isLoaded() {
		return loaded;
	}
};

#endif /* ENEMYFACTORY_H_ */
