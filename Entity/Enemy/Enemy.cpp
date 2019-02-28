/*
 * Enemy.cpp
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#include "Enemy.h"
#include <cmath>
#include <iostream>


Enemy::~Enemy() {

}

void Enemy::takeTurn_Craft(Craft* craft) {
	Entity::useCraft(craft);
}

void Enemy::takeTurn_Art(Art* art, Position tar) {
	Entity::useArt(art, tar);
}

void Enemy::moveEntity(Position positions) {
	if(getDistanceToPoint(positions) > getSPD()) {
		std::cout << "This is an error, please tell someone that " << getName() << " has a SPD/distance issue.\n\n";
		return;
	}

	for(int i = 0; i < (signed)getEntities().size(); i++) {
		if(getEntities()[i]->getPositions()[0] == positions[0] && getEntities()[i]->getPositions()[1] == positions[1]) {
			return;
		}
	}


	setPositions(positions);
}

bool Enemy::isEnemy(Entity* entity) {
	for(int i = 0; i < (signed)Entity::getEnemies().size(); i++) {
		if(entity == Entity::getEnemies()[i]) {
			return true;
		}
	}
	return false;
}

void Enemy::useCraft(Craft* usedCraft, Entity* character, bool followUpAttack) {
	std::string nice;

	int damageDealt = getAttackModifier() + usedCraft->getBaseDamage();

	if(isEnemy(character) && damageDealt >= 0) {
		return;
	} else if(!isEnemy(character)) {
		if(getPhysicalModifier(character) >= 0) {
			damageDealt += getPhysicalModifier(character);
		} else {
			damageDealt *= 0.5;
		}
	}

	if(!isEnemy(character)) {
		if(!isHit(character)) {
			std::cout << this->getName() << " tried to use " << usedCraft->getName() << " but missed.\nPress enter to continue.\n\n" << character->getName() << " counter attacks!\n\n";

			character->useCraft(getBasicAttack(), this);
			//getline(std::cin, nice);
			return;
		}
	}

	std::cout << this->getName() << " used " << usedCraft->getName() << "." << std::endl;
	std::cout << "It did " << damageDealt << " damage to " << character->getName() << ".\n\nPress enter to continue." << std::endl;
	getline(std::cin, nice);


	character->setHP(character->getHP() - damageDealt);
}


Entity* Enemy::findClosestCharacterInRange() {
	int min = getDistanceToPoint(getCharacters()[0]->getPositions());
	int distance;
	Entity* closestCharacter = getCharacters()[0];
	for(int i = 1; i < (signed)getCharacters().size(); i++) {
		distance = getDistanceToPoint(getCharacters()[i]->getPositions());
		if(distance < min) {
			closestCharacter = getCharacters()[i];
		}
	}
	return closestCharacter;
	//return Entity::getCharacters()[0];
}
