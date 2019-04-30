/*
 * inputSelectEnemy.cpp
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */

#include "Entity.h"
#include <iostream>
#include <string>
#include <algorithm>
extern int convertPosition(std::string newPosition);
extern void enterPause();

//which = 0 = enemy, 1 = character, 2 = all

Entity* inputSelectEntity(int which = 0) {

	std::vector<Entity*> enemies = Entity::getEnemies();
	std::vector<Entity*> characters = Entity::getCharacters();

	std::cout
			<< "Please select an entity by inputting it's corresponding number.\n";
	if (which == 0) {
		//std::sort(enemies.begin(), enemies.end(), [](Entity* a, Entity* b) {return a->getPositions()[0] < b->getPositions()[0];});
		for (int i = 0; i < (signed) enemies.size(); i++) {
			std::cout << "(" << i + 1 << ")\t"
					<< enemies[i]->getPositions()[0] + 1 << "-"
					<< enemies[i]->getPositions()[1] + 1 << "\t\t"
					<< enemies[i]->getName() << std::endl;
		}
	} else if (which == 1) {
		for (int i = 0; i < (signed) characters.size(); i++) {
			std::cout << "(" << i + 1 << ")\t" << characters[i]->getName()
					<< "\t\t" << characters[i]->getPositions()[0] + 1 << "-"
					<< characters[i]->getPositions()[1] + 1 << std::endl;
		}
	} else if (which == 2) {
		for (int i = 0; i < (signed) Entity::getEntities().size(); i++) {
			std::cout << "(" << i + 1 << ")\t"
					<< Entity::getEntities()[i]->getName() << "\t\t"
					<< Entity::getEntities()[i]->getPositions()[0] + 1 << "-"
					<< Entity::getEntities()[i]->getPositions()[1] + 1
					<< std::endl;
		}
	} else {
		std::cout
				<< "This is a bug :^)\n\nReport inputSelectEntity to someone.";
		return Entity::getEnemies()[0];
	}

	std::string input;
	getline(std::cin, input);
	if (input == "") {
		input = "-1";
	}
	int index = convertPosition(input);

	if (index < 0) {
		std::cout << "This is not a valid selection\n\n";
		which = index;
		enterPause();
		return NULL;
	}
	if (which == 0 && index < (signed) enemies.size()) {
		return enemies[index];
	} else if (which == 1 && index < (signed) characters.size()) {
		return characters[index];
	} else if (which == 2 && index < (signed) Entity::getEntities().size()) {
		return Entity::getEntities()[index];
	} else {
		std::cout << "This is not a valid selection\n\n";
		enterPause();
		return NULL;
	}

	return NULL;

}

