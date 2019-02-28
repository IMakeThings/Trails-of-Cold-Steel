#include "Entity.h"

#include <iostream>
#include <cmath>

extern std::vector<Position> AoE(Position startingPosition, int size, bool showAoE = false);

std::vector<Entity*> Entity::madeEnemies;
std::vector<Entity*> Entity::madeCharacters;
std::vector<Entity*> Entity::madeEntities;

extern int convertPosition(std::string newPosition);



Entity::~Entity() {
	crafts.clear();
	arts.clear();
	equipment.clear();
	quartz.clear();
	delete masterQuartz;
	delete basicAttack;
	for(int i = 0; i < (signed)madeEntities.size(); i++) {
		if(madeEntities[i] == this) {
			madeEntities.erase(madeEntities.begin() + i);
		}
	}
	for(int i = 0; i < (signed)madeEnemies.size(); i++) {
		if(madeEnemies[i] == this) {
			madeEnemies.erase(madeEnemies.begin() + i);
		}
	}
	for(int i = 0; i < (signed)madeCharacters.size(); i++) {
		if(madeCharacters[i] == this) {
			madeCharacters.erase(madeCharacters.begin() + i);
		}
	}
}

void Entity::useCraft(std::string stringCraft, Entity* enemy) {
	//Converts craft name to craft object.
	useCraft(findCraft(stringCraft),enemy);
}

void Entity::useCraft(std::string stringCraft) {
	useCraft(findCraft(stringCraft));
}




bool Entity::findCraft(Craft* c) {
	for(int i = 0; i < (signed)crafts.size(); i++) {
		if(crafts[i] == c) {
			return true;
		}
	}
	return false;
}

Craft* Entity::findCraft(std::string c) {
	if(c.length() == 1) {
		int pos = convertPosition(c);
		if(pos < (signed)crafts.size() && pos >= 0) {
			return crafts[pos];
		}
	}
	return NULL;
}



void Entity::useArt(std::string stringArt, Entity* enemy) {
	useArt(findArt(stringArt),enemy);
}

void Entity::useArt(std::string stringArt, Position pos) {

}

void Entity::useArt(Art* usedArt, Position pos) {
}

Art* Entity::findArt(std::string a) {
	if(a.length() == 1) {
		int pos = convertPosition(a);
		if(pos < (signed)arts.size() && pos >= 0) {
			return arts[pos];
		}
	}
	return NULL;
}




void addEquipment(std::string e) {

}

void Entity::removeEquipment(Equipment* e) {
	for(int i = 0; i < (signed)equipment.size(); i++) {
		if(equipment[i] == e) {
			equipment.erase(equipment.begin() + i);
		}
	}
}






void Entity::addQuartz(Quartz* q) {
	if(quartz.size() <= 8) {
		quartz.push_back(q);
	}
	updateStats_Quartz();
}

int Entity::getPhysicalModifier(Entity* enemy) {
	return floor((totalStats[2] - enemy->getTotalStats()[3])/10);
}

int Entity::getMagicModifier(Entity* enemy) {
	return floor((totalStats[4] - enemy->getTotalStats()[5])/10);
}



void Entity::moveEntity(Position positions) {
	for(int i = 0; i < 2; i++) {
		if(positions[i] < 0 || positions[i] > 16) {
			std::cout << "You cannot move here\n";
			enterPause();
			takeTurn();
		}
	}

	for(int i = 0; i < (signed)madeEntities.size(); i++) {
		if(madeEntities[i]->getPositions()[0] == positions[0] && madeEntities[i]->getPositions()[1] == positions[1]) {
			std::cout << "There is already someone here\n";
			enterPause();
			takeTurn();
			return;
		}
	}





	if(getDistanceToPoint(positions) > totalStats[9]) {
		std::cout << "You cannot move here\n";
		enterPause();
		takeTurn();
		return;
	}

	currentPosition = positions;
}



bool Entity::isHit(Entity* entity) {
	 int hitChance = int(float(getDEX())/(float(getDEX())+ float(entity->getAGL())) * 100);
	 float accuracy = Dice::rollDx(1,100,0);

	 if(accuracy <= hitChance) {
		 return true;
	 }
	 return false;
}

Position Entity::findClosestPositionToPointInRange(Position tar) {
	std::vector<Position> attackPoints = AoE(tar, getTotalStats()[10]);
	Position closestPoint;
	int minDist = getDistanceToPoint(attackPoints[0]);

	for(int i = 1; i < (signed)attackPoints.size(); i++) {
		if(getDistanceToPoint(attackPoints[i]) < minDist) {
			//closestPoint[1] = getDistanceToPoint(attackPoints[i]);
			closestPoint = attackPoints[i];
		}
	}

	return closestPoint;
}

Position Entity::findClosestPositionOfAttackPoints(std::vector<Position> attackPoints) {
	Position closestPoint = attackPoints[0];

	for(int i = 1; i < (signed)attackPoints.size(); i++) {
		if(getDistanceToPoint(attackPoints[i]) < getDistanceToPoint(closestPoint)) {
			closestPoint = attackPoints[i];
		}
	}
	return closestPoint;
}

Position Entity::getXYdistanceToPoint(Position positions) {
	Position dist;

	dist[0] = abs(positions[0] - currentPosition[0]);
	dist[1] = abs(positions[1] - currentPosition[1]);

	return dist;
}








