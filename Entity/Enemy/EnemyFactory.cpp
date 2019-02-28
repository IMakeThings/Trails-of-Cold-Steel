/*
 * EnemyFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "EnemyFactory.h"

std::map<std::string, std::function<Enemy*()>> EnemyFactory::enemyMap;
bool EnemyFactory::loaded = false;

EnemyFactory::EnemyFactory() {
	return;
}

void EnemyFactory::loadEnemies() {
	loaded = true;
	enemyMap["001E"] = []() -> Enemy* {return new FlyingFeline({0,0});};
}





